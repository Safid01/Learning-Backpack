using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practice1
{
    internal class Person
    {
        private int id;
        private float salary;
        private string name;

        public void setId(int id)
        {
            this.id = id;
        }

        public int getId()
        {
            return id;
        }

        public void setSalary(float salary)
        {
            this.salary = salary;
        }

        public float getSalary()
        {
            return salary;
        }

        public void setName(string name)
        {
            this.name = name;
        }

        public string getName()
        {
            return name;
        }
    }
}
