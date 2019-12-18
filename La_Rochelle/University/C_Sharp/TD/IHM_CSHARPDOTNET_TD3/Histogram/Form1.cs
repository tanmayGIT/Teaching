using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.Serialization.Formatters.Binary;


namespace Histogram
{
    public partial class Form1 : Form
    {
        Histogram myHisto;
        bool m_saved = false;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Random rnd = new Random();

            myHisto = new Histogram(10);
            for (int i = 0; i < myHisto.m_size; i++)
                myHisto.m_list.Add( new Intervalle(i, rnd.Next(0, 99)));
         
        }

        

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.S)
            {
                m_saved = true;
                System.IO.FileStream output = new System.IO.FileStream("test.dat", System.IO.FileMode.Create, System.IO.FileAccess.Write);

                BinaryFormatter writer = new BinaryFormatter();

                writer.Serialize(output, myHisto);
                output.Close();

            }
            if (e.KeyData == Keys.L)
            {
                if (m_saved)
                {
                   
                    
                    System.IO.FileStream input = new System.IO.FileStream("test.dat", System.IO.FileMode.Open, System.IO.FileAccess.Read);
                    BinaryFormatter loader = new BinaryFormatter();
                    myHisto = loader.Deserialize(input) as Histogram; 
                    input.Close();

                }

            }


            if (e.KeyData == Keys.C)
            {
                for (int i = 0; i < myHisto.m_size; i++)
                    myHisto.m_list[i].m_amount = 0;
            }


        }

    }
}
