using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Main_Menu
{
    public partial class Settings_Form : Form
    {
        public Settings_Form()
        {
            InitializeComponent();
        }

        private async void button2_Click(object sender, EventArgs e)
        {

            string choice1="Blue", choice2="Pink";
            if (radioButton1.Checked)
            {
                choice1 = "Blue";
            }
            else if (radioButton2.Checked)
            {
                choice1 = "Brown";
            }
            else if (radioButton3.Checked)
            {
                choice1 = "Gray";
            }
            if (radioButton5.Checked)
            {
                choice2 = "Pink";
            }
            if (radioButton4.Checked)
            {
                choice2 = "Green";
            }
            if (radioButton6.Checked)
            {
                choice2 = "Purple";
            }
            string text = textBox1.Text+"@"+choice1+"@"+textBox2.Text+"@"+choice2;  //Seperated by '@' Char
            await File.WriteAllTextAsync("Settings_Info.txt", text);
            this.Hide();
            this.Close();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
