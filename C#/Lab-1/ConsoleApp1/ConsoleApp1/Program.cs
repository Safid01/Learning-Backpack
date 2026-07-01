using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /* Console.WriteLine("ASDf");
            Console.WriteLine("ASDf");

            int a = 9;
            float b = 3.4f;
            double c = 6.6;
            string d = "Hi there";

            Console.WriteLine("Integer value:{1} {0}", b, a);
            Console.WriteLine("Integer value:{2} {0} {1}", c, a, b);
            Console.WriteLine("Double value:" + c + " " + d + " " + a);
            Console.WriteLine($"d is: {d}{c}");


            Console.Write("Enter your name:");
            string aa = Console.ReadLine();
            Console.WriteLine("Inserted name:" + aa);

            Console.Write("Enter your name:");
            int bb = int.Parse(Console.ReadLine());
            Console.WriteLine("Inserted name:" + bb);

            Console.WriteLine("Enter your salary");
            float cc = float.Parse(Console.ReadLine());
            Console.WriteLine("Inserted salary:" + cc);

            Console.WriteLine("Enter your salary");
            double dd = double.Parse(Console.ReadLine());
            Console.WriteLine("Inserted salary:" + dd);

            int sd = 10;
            if (sd > 18)
            { Console.WriteLine("Good"); }
            else if (sd == 10)
            { Console.WriteLine("Neutral"); }
            else
            { Console.WriteLine("Bad");  }


            int bc = 2;
            switch (bc)
            {   case 1:
                    Console.WriteLine("one");
                    break;
                case 2:
                    Console.WriteLine("cfj");
                    break;
                default:
                    Console.WriteLine("none");
                    break;
            } 


            int i;
            for (i = 0; i < 5; i++)
            {  Console.WriteLine(i); }
            while (i < 10)
            { Console.WriteLine(i);
                i++;
            }
            do
            { Console.WriteLine(i);
                i++;
            } while (i < 15);  */

            string[] students = new string[5];
            Console.WriteLine("Enter students:");
            for (int i = 0; i < 5; i++)
            {
                students[i] = Console.ReadLine();
            }
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("students- [" + i + "]: " + students[i]);
            }
            for (int i = 0; i < students.Length; i++)
            {
                Console.WriteLine("students- [" + i + "]: " + students[i]);
            }
            foreach (string s in students)
            {
                Console.WriteLine("foreach: " + s);
            }
            foreach (var s in students)
            {
                Console.WriteLine("foreach: " + s);
            }

            var a = 2;
            var b = 3.3;
            var c = "Hll";
            Console.WriteLine("int: " + a);
            Console.WriteLine("double: " + b);
            Console.WriteLine("string: " + c);  

            Console.ReadKey();
        }
    }
}
