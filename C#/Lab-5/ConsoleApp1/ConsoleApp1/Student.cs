using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Student
    {
        //static vs instance variable
        public string Name;
        public int Id;

        public static string University = "AIUB";


        public void Display()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("ID: " + Id);
            Console.WriteLine("University: " +University);
            Console.WriteLine("-----------------");
        }

    }
}
