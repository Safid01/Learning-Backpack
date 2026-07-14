using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //static vs instance variable
            Student student1 = new Student();
            student1.Name = "Messi";
            student1.Id = 10;

            Student student2 = new Student();
            student2.Name = "Ronaldo";
            student2.Id = 7;

            student1.Display();
            student2.Display();

            Student.University = "CalTech";

            student1.Display();
            student2.Display();



            //static vs Instance method
            Console.WriteLine(Calculator.Add(3,4));

            Calculator c1=new Calculator();
            Console.WriteLine(c1.Multiply(5,6));



            //Static vs instance constructor

           Employee e1 = new Employee();
           Employee e2 = new Employee();




            Console.ReadKey();
        }
    }
}
