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
            Student student1 = new Student();
            Console.Write("Enter your name:");
            student1.Name = Console.ReadLine();
            Console.Write("Enter your age:");
            student1.Age=Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter your cgpa:");
            student1.CGPA=Convert.ToDouble(Console.ReadLine());

            Student student2 = new Student("Nothing",0,0.00);
            Console.Write("Enter your name:");
            student2.Name = Console.ReadLine();
            Console.Write("Enter your age:");
            student2.Age = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter your cgpa:");
            student2.CGPA = Convert.ToDouble(Console.ReadLine());

            student1.Display();
            student2.Display();

            Console.Write("Enter your name:");
            string namex = Console.ReadLine();
            Console.Write("Enter your age:");
            int agex = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter your cgpa:");
            double CGPAX = Convert.ToDouble(Console.ReadLine());
            Student student3 = new Student(namex, agex, CGPAX);
            student3.Display();



            Console.ReadKey();

        }
    }
}
