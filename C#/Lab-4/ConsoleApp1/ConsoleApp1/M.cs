using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class M
    {
        static void Main(string[] args)
        { //default constructor
            Person p1 = new Person();
            p1.setId(1);
            p1.setName("Rahim");
            p1.setSalary(200);
            p1.printDetails();
            //parameterized constructor
            Person p2 = new Person(2, "Karim", 300);
            p2.printDetails();

            Manager m1 = new Manager(2, "asad", 400, 5);
            m1.printDetails();
            m1.printDetailsp(); 

            Person[] Person1 = new Person[2];
           // Person1[0] = p1;
           // Person1[1] = p2;
            for (int i = 0; i < Person1.Length; i++)
            {Person1[i] = new Person();
                Console.WriteLine("Enter your ID: ");
                Person1[i].setId(int.Parse(Console.ReadLine()));
                Console.WriteLine("Enter your Salary: ");
                Person1[i].setSalary(float.Parse(Console.ReadLine()));
                Console.WriteLine("Enter your Name: ");
                Person1[i].setName(Console.ReadLine()); } 
            for (int i = 0; i < Person1.Length; i++)
            {
                /* Console.WriteLine("--------------------------");
                Console.WriteLine("Inserted Id: " + Person1[i].getId());
                Console.WriteLine("Inserted name: " + Person1[i].getName());
                Console.WriteLine("Inserted salary: " + Person1[i].getSalary()); */

                Person1[i].printDetails();
                Person1[i].printDetailsp();
            }


            Console.ReadKey();  
        }
    }
}
