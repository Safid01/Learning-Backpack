using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Person
    {
        private int id;
        private string name;
        private float salary;
        public Person()
        { Console.WriteLine("Default one executed");
        }
        public Person(int id, string name, float salary)
        {   Console.WriteLine("Parameterized one executed-Person");
            this.id = id;
            this.name = name;
            this.salary = salary;
        }


        public void setId(int id)
        { this.id = id; }
        public void setName(string name)
        { this.name = name; }
        public void setSalary(float salary)
        { this.salary = salary; }


        public int getId()
        { return this.id; }
        public string getName()
        { return this.name; }
        public float getSalary()
        { return this.salary; }


        public void printDetails()
        {
            Console.WriteLine("User id: " + id);
            Console.WriteLine("User name:" + name);
            Console.WriteLine("User salary: " + salary);
        }

        public virtual void printDetailsp()
        {
            Console.WriteLine("User id: " + id);
            Console.WriteLine("User name:" + name);
            Console.WriteLine("User salary: " + salary);
        }






    }
}
