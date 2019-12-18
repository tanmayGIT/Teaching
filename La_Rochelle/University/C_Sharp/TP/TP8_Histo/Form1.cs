using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace exo2_serialize.cs
{
    public partial class Form1 : Form
    {
        Histogram myHisto;
        bool m_saved = false;
        bool m_loaded = false;
        bool m_pie = false;

        public Form1()
        {
            InitializeComponent();
            this.ResizeRedraw = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            myHisto = new Histogram(10);

        }



        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            this.Invalidate();

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

            if (e.KeyData == Keys.R)
            {
            Random rnd = new Random();
            for (int i = 0; i < myHisto.m_size; i++)
            {
                myHisto.m_list[i].m_amount = rnd.Next(0, 99);
            }
            Invalidate();
            this.toolStripStatusLabel1.Text = "Histogram randomly created!";
            }



            if (e.KeyData == Keys.C)
            {
                for (int i = 0; i < myHisto.m_size; i++)
                    myHisto.m_list[i].m_amount = 0;
            }


        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            if (m_loaded)
            {
                if (!m_pie)
                {
                    int display_w = e.ClipRectangle.Width;
                    int display_h = e.ClipRectangle.Height;


                         int base_h = display_h - 20;


                  int  ratio = 1; // a faire mais classique
                    for (int i = 0; i < myHisto.m_size; i++)
                    {
                        //              Rectangle boundingRect = new Rectangle(20 + (i * 30), display_h,  50 + (i * 30),   display_h - (20 + (int) myHisto.m_list[i].m_amount ));                      
//                        Rectangle boundingRect = new Rectangle(5 + (i * 20), (base_h - (int)ratio * myHisto.m_list[i].m_amount), 20, (int)(ratio * myHisto.m_list[i].m_amount));
                        Rectangle boundingRect = new Rectangle(5 + (i * 20), (base_h - (int)ratio * myHisto.m_list[i].m_amount), 20, (int)(ratio * myHisto.m_list[i].m_amount));

                        //          rect = new CRect(20 + (i * 30), base, 50 + (i * 30), r.bottom - (20 + (int)h)); 


                        e.Graphics.FillRectangle(Brushes.Red, boundingRect);

                        e.Graphics.DrawRectangle(Pens.Black, boundingRect);
                    }
                    //           grx.FillEllipse(new SolidBrush(Color.Red), boundingRect);

                }
      
           
            if (m_pie)
            {

                int display_w = e.ClipRectangle.Width;
                int display_h = e.ClipRectangle.Height;
    
                              Color[] Colors = new Color[] {
        Color.Red, Color.LightGreen, Color.Blue,
        Color.Pink, Color.Green, Color.LightBlue,
        Color.Orange, Color.Yellow, Color.Purple,Color.Beige
    };
                float total=0;
                for(int i=0;i<myHisto.m_size;i++)
                    total += myHisto.m_list[i].m_amount;

                float[] deg = new float[myHisto.m_size];
           for(int i=0;i<myHisto.m_size;i++)
              deg[i] =   (float) ((myHisto.m_list[i].m_amount/ total) * 360);

           Rectangle rec = new Rectangle(40, 40, display_h-20, display_h-20);
                float sum_angle =0;

          for(int i=0;i<myHisto.m_size;i++){
              e.Graphics.FillPie(new SolidBrush(Colors[i]), rec, sum_angle,deg[i] );
              sum_angle += deg[i];
           }
        

            }

        }

 }



        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < myHisto.m_size; i++)
                myHisto.m_list[i].m_amount = 0;
            this.toolStripStatusLabel1.Text = "Histogram cleared!";
  
            Invalidate();
    
        }

        private void loadToolStripMenuItem_Click(object sender, EventArgs e)
        {

      
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            //         saveFileDialog1.ShowDialog();







            Stream myStream;

            StreamReader sr;


            openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if ((myStream = openFileDialog1.OpenFile()) != null)
                {
                    // Code to write the stream goes here.
                    sr = new StreamReader(myStream);
                    string line ;
                    string[] stringArray;


                    line = sr.ReadLine();

                    while (line != null)
                    {
                         stringArray = line.Split(' ');
//                        myHisto.m_list.Add(new Intervalle(Convert.ToUInt32(stringArray[0]), Convert.ToUInt32(stringArray[1])));
                        int m_x, m_y;
                        int.TryParse(stringArray[0], out m_x);
                        int.TryParse(stringArray[1], out m_y);
                        
                
                            myHisto.m_list.Add(new Intervalle(m_x, m_y));
                            line = sr.ReadLine();
 
            }
                    sr.Close();
                    //   myStream.Write(mytable, 0, mytable.Length);
                    myStream.Close();
                }

                m_loaded = true;
            }
 











            Invalidate();
            this.toolStripStatusLabel1.Text = "Histogram loaded!";
  
        }

        private void sAVEToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_saved = true;
            System.IO.FileStream output = new System.IO.FileStream("test_histo.dat", System.IO.FileMode.Create, System.IO.FileAccess.Write);

            BinaryFormatter writer = new BinaryFormatter();

            writer.Serialize(output, myHisto);
            output.Close();
            this.toolStripStatusLabel1.Text = "Histogram saved!";
  
            Invalidate();

        }

        private void restoreToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (m_saved)
            {


                System.IO.FileStream input = new System.IO.FileStream("test_histo.dat", System.IO.FileMode.Open, System.IO.FileAccess.Read);
                BinaryFormatter loader = new BinaryFormatter();
                myHisto = loader.Deserialize(input) as Histogram;
                input.Close();
      //          Graphics toto = toolStripStatusLabel1.d
                Invalidate();
            this.toolStripStatusLabel1.Text  = "Histogram restored!";
            }

 
        }

        private void randomToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Random rnd = new Random();
            for (int i = 0; i < myHisto.m_size; i++)
            {
                myHisto.m_list[i].m_amount = rnd.Next(0, 99);
            }
            Invalidate();
            this.toolStripStatusLabel1.Text = "Histogram randomly created!";
        }

        private void pieToolStripMenuItem_Click(object sender, EventArgs e)
        {
        m_pie = true;
        this.Invalidate();

        }

   
    }
}
