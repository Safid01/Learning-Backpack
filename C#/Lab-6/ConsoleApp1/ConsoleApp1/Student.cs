using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Student: Person
    {
        public double CGPA;

        public Student(): base() 
        {
           CGPA = 0;
        }

        public Student(string name, int age, double cGPA): base(name, age)
        {
            CGPA = cGPA;
        }

        public override void Display()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Age: " + Age);
            Console.WriteLine("CGPA: " + CGPA);
            Console.WriteLine("-------------------");
        }
    }
}
