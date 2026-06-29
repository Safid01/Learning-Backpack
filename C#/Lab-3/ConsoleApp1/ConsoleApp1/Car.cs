using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Car
    {
        private int lid;
        private string model;
        private int cc;
        public void setLid(int lid)
        { this.lid = lid; }
        public void setModel(string model) 
        { this.model = model;}
        public void setCc(int cc)
        { this.cc = cc;}
        public int getLid() 
        { return this.lid;} 
        public string getModel() 
        { return this.model;}
        public int getcc() 
        { return this.cc;}

        public void display()
        {
            Console.WriteLine("-------------");
            Console.WriteLine("LID: " + lid);
            Console.WriteLine("Model: "+ model);
            Console.WriteLine("CC: " + cc);
            Console.WriteLine("-------------");
        }

       /* static void Main(string[] args)
        {
            Car car1 = new Car();
            car1.setLid(1);
            car1.setModel("asdf");
            car1.setCc(1000);

           Console.WriteLine(car1.getLid());
            Console.WriteLine(car1.getModel());
            Console.WriteLine(car1.getcc()); 


            Car car2 = new Car();
            car2.setLid(2);
            car2.setModel("zsdf");
            car2.setCc(2000);


            car1.display();
            car2.display();


            Console.ReadKey();
        } */
    }
}
