using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Person
{
    internal class Start
    {
        static void Main(string[] args)
        {
            Person p1 = new Person("Alice", 30);
            p1.DisplayInfo();
            Manager m1 = new Manager("Bob", 40, 15);
            m1.DisplayInfo();
            Console.ReadKey();
        }
    }
}