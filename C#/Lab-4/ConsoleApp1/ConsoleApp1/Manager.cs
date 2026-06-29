using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Manager : Person
    {
        private int yearsOE;
        public Manager(int id, string name, float salary,int yearsOE) 
            : base(id, name, salary)
        {
            Console.WriteLine("Parameterized one executed-Manager");
            this.yearsOE = yearsOE;
        }
        public void setYearsOE(int yearsOE)
        { this.yearsOE = yearsOE; }
        public int getYearsOE() { return yearsOE; }
        public void printDetails()
        {
           /* Console.WriteLine("User id: " + base.getId());
             Console.WriteLine("User name:" + base.getName());
             Console.WriteLine("User salary: " + base.getSalary());*/
            Console.WriteLine("YEA: " + yearsOE);

            base.printDetails();
        }
        public override void printDetailsp()
        {
            base.printDetailsp();
            Console.WriteLine("YEA: " + yearsOE);
        }




    }
}
