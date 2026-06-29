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
        }
    }
}
