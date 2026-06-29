using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Person
{
    internal class Manager:Person
    {
        private int yearsOfExperience;
        public Manager(string name, int age, int yearsOfExperience) : base(name, age)
        {
            this.yearsOfExperience = yearsOfExperience;
            Console.WriteLine($"Manager created: {GetName()}, {GetAge()}, {yearsOfExperience} years of experience");
        }
        public void SetYearsOfExperience(int years)
        {
            this.yearsOfExperience = years;
        }
        public int GetYearsOfExperience()
        {
            return yearsOfExperience;
        }
        public override void DisplayInfo()
        {
            base.DisplayInfo();
            Console.WriteLine($"Years of Experience: {yearsOfExperience}");
        }
    }
}