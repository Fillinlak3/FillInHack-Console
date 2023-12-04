using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Diagnostics;
using System.Net;
using System.Runtime.InteropServices;
using System.Text.RegularExpressions;

internal class Program
{
    // ===================================================
    // -------------------- Variables --------------------
    // ===================================================

    static string url = "https://pastebin.com/raw/gTNMMSw1"; // Versions Database
    static string console_program_version = "1.0.0";
    static string encryptor_program_version = "1.0.0";
    static string help_program_version = "1.0.0";
    static string program_path = "";
    static string main_path = "";
    static string versions_file_name = Path.GetTempPath() + "versions.fih";
    static Process? console_program_process;
    static Dictionary<string, string>? versions_scraped;
    static string config_file_name = "";
    static bool status = true;

    enum CtrlType
    {
        CTRL_C_EVENT = 0,
        CTRL_BREAK_EVENT = 1,
        CTRL_CLOSE_EVENT = 2,
        CTRL_LOGOFF_EVENT = 5,
        CTRL_SHUTDOWN_EVENT = 6
    }

    // ==================================================================
    // -------------------- Function Implementations --------------------
    // ==================================================================

    [DllImport("Kernel32")]
    static extern bool SetConsoleCtrlHandler(EventHandler handler, bool add);
    delegate bool EventHandler(CtrlType sig);

    static bool CtrlHandler(CtrlType __type)
    {
        switch (__type)
        {
            case CtrlType.CTRL_C_EVENT:
                return true;
            case CtrlType.CTRL_BREAK_EVENT:
                return true;
            case CtrlType.CTRL_CLOSE_EVENT:
                File.Delete(versions_file_name);
                return false;
            case CtrlType.CTRL_LOGOFF_EVENT:
                return false;
            case CtrlType.CTRL_SHUTDOWN_EVENT:
                return false;
            default:
                return false;
        }
    }

    static void __getPaths()
    {
        // Get Runnables path and console program path.
        foreach (string item in AppDomain.CurrentDomain.BaseDirectory.Split('\\'))
        {
            main_path += item + @"\";
            if (item == "Runnables")
                break;
        }
        program_path = main_path + "FillInHack Console.exe";
        config_file_name = main_path + "programs.config";
    }

    // =======================================================
    // -------------------- Main Function --------------------
    // =======================================================

    private static void Main(string[] args)
    {
        SetConsoleCtrlHandler(CtrlHandler, true);
        Console.WriteLine("Checking FillInHack Console for updates...");
        __getPaths();

        // Setup launch application.
        console_program_process = new Process();
        console_program_process.StartInfo.FileName = program_path;
        console_program_process.StartInfo.WorkingDirectory = main_path;
        console_program_process.StartInfo.UseShellExecute = false;

        using (WebClient web = new WebClient())
        {
            versions_scraped = new Dictionary<string, string>();
            try
            {
                #region Web Scraping Tool
                List<string>? data_scraped = new List<string>(web.DownloadString(url).Split('\n', StringSplitOptions.TrimEntries).ToArray());

                // Remove comment lines.
                for (int i = 0; i < data_scraped.Count; i++)
                    if (data_scraped[i].StartsWith('#'))
                        data_scraped.Remove(data_scraped[i]);

                // Parse values into the dictionary.
                foreach (var item in data_scraped)
                {
                    string[] get_item = item.Split(':', ',', ';').ToArray();
                    string key, value;
                    if (!string.IsNullOrEmpty(get_item[0]) && !string.IsNullOrEmpty(get_item[1]))
                    {
                        key = get_item[0].Replace('\"', ' ').Trim();
                        value = get_item[1].Replace('\"', ' ').Trim();
                        versions_scraped.Add(key, value);
                    }
                }
                data_scraped = null;
                #endregion

                #region Check if the scraped info is valid
                // Check if versions were gathered from url.
                if (versions_scraped == null || versions_scraped.Count == 0)
                    throw new Exception("Couldn't retrive data from server.");

                // Check if versions have syntax: x.x.x where x is a digit.
                Regex rx = new Regex("^[1-9].[0-9].[0-9]$", RegexOptions.Compiled | RegexOptions.IgnoreCase);
                if (!rx.IsMatch(versions_scraped["Console Program"]) || !rx.IsMatch(versions_scraped["Encryptor"]) ||
                    !rx.IsMatch(versions_scraped["Help"]))
                    throw new Exception("Corrupted or invalid data retrieved.");
                #endregion
            }
            catch (Exception ex)
            {
                // Outputs the error, then quit.
                Console.WriteLine("An error occured: " + ex.Message);
                Console.ReadKey();
                Environment.Exit(1);
            }
            finally
            {
                // Write temp file for console to be checked.
                string fw = $"\"Console Program\": \"{versions_scraped["Console Program"]}\",\n" +
                $"\"Encryptor\": \"{versions_scraped["Encryptor"]}\",\n\"Help\": \"{versions_scraped["Help"]}\";";
                File.WriteAllText(versions_file_name, fw);
            }
        }

        try
        {
            JObject config_file = JObject.Parse(File.ReadAllText(config_file_name));

            if (config_file.Count == 0 || config_file == null)
                throw new Exception("Couldn't find config file.");

            #region Check Programs Versions
#pragma warning disable CS8602 // Dereference of a possibly null reference.
            // Check Console_Program version.
            if (versions_scraped.ContainsKey("Console Program") && versions_scraped["Console Program"] == console_program_version &&
                config_file.ContainsKey("Console Program") && config_file.GetValue("Console Program")["version"].ToString() == console_program_version)
            { Console.Write("Program - "); Console.ForegroundColor = ConsoleColor.Green; Console.WriteLine("OK"); Console.ResetColor(); }
            else
            { Console.Write("Program - "); Console.ForegroundColor = ConsoleColor.Red; Console.Write("UPDATE FOUND "); Console.ResetColor(); Console.WriteLine($"(ver: {versions_scraped["Console Program"]})"); status = false; }

            // Check Encryptor_Program version.

            if (versions_scraped.ContainsKey("Encryptor") && versions_scraped["Encryptor"] == encryptor_program_version &&
                config_file.ContainsKey("Encryptor Program") && config_file.GetValue("Encryptor Program")["version"].ToString() == encryptor_program_version)
            { Console.Write("Encryptor - "); Console.ForegroundColor = ConsoleColor.Green; Console.WriteLine("OK"); Console.ResetColor(); }
            else
            { Console.Write("Encryptor - "); Console.ForegroundColor = ConsoleColor.Red; Console.Write("UPDATE FOUND "); Console.ResetColor(); Console.WriteLine($"(ver: {versions_scraped["Encryptor"]})"); status = false; }


            // Check Help_Program version.
            if (versions_scraped.ContainsKey("Help") && versions_scraped["Help"] == help_program_version &&
                config_file.ContainsKey("Help Program") && config_file.GetValue("Help Program")["version"].ToString() == help_program_version)
            { Console.Write("Help - "); Console.ForegroundColor = ConsoleColor.Green; Console.WriteLine("OK"); Console.ResetColor(); }
            else
            { Console.Write("Help - "); Console.ForegroundColor = ConsoleColor.Red; Console.Write("UPDATE FOUND "); Console.ResetColor(); Console.WriteLine($"(ver: {versions_scraped["Help"]})"); status = false; }
#pragma warning restore CS8602 // Dereference of a possibly null reference.
            #endregion
        }
        catch (FileNotFoundException)
        {
            File.Delete(versions_file_name);
            Console.WriteLine("Couldn't find config file.");
            Console.ReadKey();
            Environment.Exit(1);
        }
        catch (JsonReaderException)
        {
            File.Delete(versions_file_name);
            Console.WriteLine("Couldn't read config file. Invalid data format.");
            Console.ReadKey();
            Environment.Exit(1);
        }
        catch (Exception e)
        {
            File.Delete(versions_file_name);
            Console.WriteLine(e);
            Console.ReadKey();
            Environment.Exit(1);
        }

        // Final status check
        if (status)
        {
            Console.WriteLine("You\'re up to date! Proceding to FillInHack Console login page..");
            Thread.Sleep(3000);
            Console.Clear();
            console_program_process.Start();
        }
        else
        {
            File.Delete(versions_file_name);
            Console.WriteLine("Please download the newest version of the program from our site.");
            Thread.Sleep(3000);
        }

        Environment.Exit(1);
    }
}