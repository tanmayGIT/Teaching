using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            DirectoryInfo di = new DirectoryInfo("../../");   // on remonte de debug, puis de bin
            foreach (FileInfo fi in di.GetFiles("*.cs"))
            {
                Console.WriteLine("Looking at file \"" + fi.FullName + "\"");
            }
            Console.ReadLine(); // attente return

            // attention, long et consomateur de mémoire, sans compter qu'il faut effacer les fichiers ensuite.
            // a lancer en ouvrant d'abord le moniteur de ressources pour la consommation mémoire.

            // le repertoire C:\Temp\test\ doit exister.

            //for (int i = 0; i < 50000; i++)
            //{
            //    System.IO.TextWriter w = System.IO.File.CreateText("C:\\Temp\\test\\log" + i + ".txt");
            //    {
            //        string msg = DateTime.Now + ", " + i;
            //        w.WriteLine(msg);
            //    }
            //    w.Close();
            //}

            Console.ReadLine(); // attente return

            // version avec using
            // on ne constate plus de différence d'utilisation mémoire....

            for (int i = 0; i < 50000; i++)
            {
                using (TextWriter w = File.CreateText("C:\\Temp\\test\\log" + i + ".txt"))
                {
                    string msg = DateTime.Now + ", " + i;
                    w.WriteLine(msg);
                }
            }

            Console.ReadLine(); // attente fermeture console

        }
    }
}
