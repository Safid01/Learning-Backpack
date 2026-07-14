using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter number of persons: ");
            int n = int.Parse(Console.ReadLine());

            Person[] Person1 = new Person[n];

            for (int i = 0; i < Person1.Length; i++)
            {
                Person1[i] = new Person();

                Console.WriteLine("Enter your ID: ");
                Person1[i].setId(int.Parse(Console.ReadLine()));

                Console.WriteLine("Enter your salary: ");
                Person1[i].setSalary(float.Parse(Console.ReadLine()));

                Console.WriteLine("Enter your name: ");
                Person1[i].setName(Console.ReadLine());
            }

            for (int i = 0; i < Person1.Length; i++)
            {
                Console.WriteLine("Person " + (i + 1) + ":");
                Console.WriteLine("Inserted ID: " + Person1[i].getId());
                Console.WriteLine("Inserted name: " + Person1[i].getName());
                Console.WriteLine("Inserted salary: " + Person1[i].getSalary());
            }

            Console.ReadKey();
        }
    }
}
