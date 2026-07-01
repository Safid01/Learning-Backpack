using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    struct students
    {
        public int id;
        public string name;
        public int age;
    }
    enum weekdays
    {
        sat,sun,mon,
        tue,
        wed,
        thu
    }

    internal class Program
    {
        static void Main(string[] args)
        {
             int[][] jg = new int[4][];

             jg[0] = new int[] { 1, 2, 3, 4 };
             jg[1] = new int[] { 2, 3, 4 };
             jg[2] = new int[] { 3 };
             jg[3] = new int[] { 4, 7, 2, 5, 6, 7 };
            for (int i = 0; i < jg.Length; i++)
             {
                 for (int j = 0; j < jg[i].Length; j++)
                 {
                     Console.Write(jg[i][j] + " ");
                 }
                 Console.WriteLine();
             }

            students s1;
            s1.id = 1;
            s1.name = "Neymar";
            s1.age = 31;

            Console.WriteLine(s1.id);
            Console.WriteLine(s1.name);
            Console.WriteLine(s1.age); 

            Console.WriteLine(weekdays.sat);
            Console.WriteLine(weekdays.sun);
            Console.WriteLine((int)weekdays.sat);
            Console.WriteLine((int)weekdays.sun);



            Console.ReadKey();
        }
    }
}
