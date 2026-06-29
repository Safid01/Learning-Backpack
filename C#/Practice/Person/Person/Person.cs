using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Person
{
    public class Person
    {
        int age;
        string name;
        public Person() { 
             Console.WriteLine("Person created");
        }

        public Person(string name, int age)
        {
            this.name = name;
            this.age = age;
            Console.WriteLine($"Person created: {name}, {age}");
        }

        public void SetName(string name)
        {
            this.name = name;
        }
        public string GetName()
        {
            return name;
        }
        public void SetAge(int age)
        {
            this.age = age;
        }
        public int GetAge()
        {
            return age;
        }
        public virtual void DisplayInfo()
        {
            Console.WriteLine($"Name: {name}, Age: {age}");
        }
    }
}