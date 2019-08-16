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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void EKLEBUTON_Click(object sender, EventArgs e)
        {
            string rnkisim = "", rnksoyisim = "", rnktel = "";
            try
            {
                //renkler ile igili kısım                
                foreach (Control radio in groupBox1.Controls)
                {
                    RadioButton rdb = (RadioButton)(radio);
                    if (rdb.Checked)
                    {
                        rnkisim = rdb.Text;
                    }
                }
                foreach (Control radio in groupBox2.Controls)
                {
                    RadioButton rdb = (RadioButton)(radio);
                    if (rdb.Checked)
                    {
                        rnksoyisim = rdb.Text;
                    }
                }
                foreach (Control radio in groupBox3.Controls)
                {
                    RadioButton rdb = (RadioButton)(radio);
                    if (rdb.Checked)
                    {
                        rnktel = rdb.Text;
                    }
                }
                //
                //Dosya Kayıt
                FileStream kayit = new FileStream("D:\\veriler.txt", FileMode.Append, FileAccess.Write);
                StreamWriter yazmaislemi = new StreamWriter(kayit);
                yazmaislemi.WriteLine(rnkisim + rnksoyisim + rnktel + " " + textisim.Text.ToString() + " " + textsoyisim.Text.ToString() + " " + texttelefon.Text.ToString());
                MessageBox.Show("Kayıt İşlemi Gerçekleştirilmiştir.");
                yazmaislemi.Close();
                textisim.Text = "";
                textsoyisim.Text = "";
                texttelefon.Text = "";
                radioButton1.Checked = true;
                radioButton4.Checked = true;
                radioButton7.Checked = true;
                //
                //
            }
            catch (Exception hata)
            {
                MessageBox.Show(hata.Message);
            }
        }
    }
}
