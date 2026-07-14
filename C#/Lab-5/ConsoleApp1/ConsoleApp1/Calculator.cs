using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Calculator
    {
        //static vs instance method
        public static int Add(int a, int b)
        { return a + b; }

        public int Multiply(int a, int b)
        {  return a * b; }
    }
}
