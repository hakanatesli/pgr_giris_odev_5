using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace g171210002
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }
        public void renkayarlama(char x)
        {
            if (x == 'K')
                richTextBox1.SelectionColor = Color.Red;            
            if (x == 'Y')
                richTextBox1.SelectionColor = Color.Green;
            if (x == 'M')
                richTextBox1.SelectionColor = Color.Blue;
        }
        private void Form3_Load(object sender, EventArgs e)
        {
            try
            {
                string satir = "";
                int sayac = 1;
                StreamReader oku = new StreamReader("D:\\veriler.txt");
                while (satir != null)
                {
                    string[] yazi;
                    satir = oku.ReadLine();
                    yazi = satir.Split(' ');
                    char[] renk = yazi[0].ToArray();
                    if (satir != null)
                    {
                        if (sayac % 2 == 1)
                        {
                            richTextBox1.SelectionFont = new Font("Verdana", 8, FontStyle.Bold);
                            renkayarlama(renk[0]);
                            richTextBox1.AppendText(yazi[1] + " ");
                            renkayarlama(renk[1]);
                            richTextBox1.AppendText(yazi[2] + " ");
                            renkayarlama(renk[2]);
                            richTextBox1.AppendText(yazi[3] + "\n");
                        }
                        else if (sayac % 2 == 0)
                        {
                            richTextBox1.SelectionFont = new Font("Verdana", 8);
                            renkayarlama(renk[0]);
                            richTextBox1.AppendText(yazi[1] + " ");
                            renkayarlama(renk[1]);
                            richTextBox1.AppendText(yazi[2] + " ");
                            renkayarlama(renk[2]);
                            richTextBox1.AppendText(yazi[3] + "\n");
                        }
                    }
                    sayac++;
                }
                oku.Close();
            }
            catch (Exception hata)
            {

            }
        }
    }
}
