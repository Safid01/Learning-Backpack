using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice
{
    internal class Test
    {
        static void Main(string[] args)
        {
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
                Console.Write("foreach: " + s);
            }
            foreach (var s in students)
            {
                Console.WriteLine("foreach: " + s);
            }

            Console.ReadKey();
        }
    }
}
