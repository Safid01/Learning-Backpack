using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Person
    {
        public string Name {  get; set; }
        public int Age { get; set; }

        public Person()
        {
            Name = "Blank";
            Age= 0;
        }

        public Person(string name, int age)
        {
            Name = name;
            Age = age;
        }

        public virtual void Display()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Age: " + Age);

        }
    }
}
