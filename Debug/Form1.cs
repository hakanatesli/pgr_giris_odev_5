using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace g171210002
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void EKLEBUTON_Click(object sender, EventArgs e)
        {
            Form2 Eklemesayfasi = new Form2();
            Eklemesayfasi.ShowDialog();
        }

        private void LİSTEBUTON_Click(object sender, EventArgs e)
        {
            Form3 Listelemesayfasi = new Form3();
            Listelemesayfasi.ShowDialog();
        }
    }
}
