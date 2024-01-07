using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Security.AccessControl;
using System.Security.Principal;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace Main_Menu
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            Thread t = new Thread(new ThreadStart(StartForm));
            t.Start();
            Thread.Sleep(5000);
            InitializeComponent();
            Application.Exit();
        }
        public void StartForm()
        {
            Application.Run(new Form2());
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //brings to front
            this.WindowState = FormWindowState.Minimized;
            this.Show();
            this.WindowState = FormWindowState.Normal;
        }

        
        private void button2_Click(object sender, EventArgs e)
        {
                Process myProcess = new Process();
                myProcess.StartInfo.UseShellExecute = false;
                // You can start any process, HelloWorld is a do-nothing example.
                myProcess.StartInfo.FileName = @"C:\Users\abdul\\Desktop\HW5_the_correct_one\HUMania\a.exe";
                myProcess.StartInfo.CreateNoWindow = true;
                myProcess.Start();
                // This code assumes the process you are starting will terminate itself.
                // Given that is is started without a window so you cannot terminate it
                // on the desktop, it must terminate itself or you can do it programmatically
                // from this application using the Kill method.
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form f = new Settings_Form();
            f.ShowDialog();

        }

        private void button5_Click(object sender, EventArgs e)
        {
            Form f = new Form3();
            f.ShowDialog();
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {

        }

        public bool status=false;
        
        private void button1_Click(object sender, EventArgs e)
        {
            using (var soundPlayer = new SoundPlayer(@"C:\Program Files\Assets\Music.wav"))
            {
                if (status == false)
                {
                    soundPlayer.Play(); // can also use soundPlayer.PlaySync()
                    status= true;
                }
                else
                {
                    soundPlayer.Stop();
                    status= false;
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide();
            this.Close();
        }
    }
}