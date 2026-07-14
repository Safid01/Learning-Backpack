using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Employee
    {
        //Static vs instance constructor
        public Employee() 
        {
            Console.WriteLine("Instance Constructor executed");
        } 

        static Employee()
        { 
            Console.WriteLine("Static constructor executed"); 
        }
    }
}
