using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TPDOTNET4
{

     public partial class Form1 : Form
    {
        int m_iterator = 0;
        Boolean m_isRunning = false;
        List<String> m_filenameList = new List<string>();
        DisplayForm m_FormA = new DisplayForm();
        DisplayForm m_FormB = new DisplayForm();
        float m_rotationAngle = 0.0F;
        public Form1()
        {
            InitializeComponent();
            m_FormA.Text = "Form A";
            m_FormB.Text = "Form B";
            timer2.Start();
           // Application.Idle +=new EventHandler(Application_Idle);

        }

      
        

        
        


        /* ETAPE 1 : affichage d'une seule image */
        //private void button1_Click(object sender, EventArgs e)
        //{
        //    String filename = String.Empty;
        //    if ((openFileDialog1.ShowDialog()) == DialogResult.OK)
        //    {
        //        textBox1.Text = filename = openFileDialog1.FileName;
        //        pictureBox1.Image = Bitmap.FromFile(filename);
        //    }
        //}

        /* ETAPE 2 : affichage de toutes les images dans un repertoire */
        private void button1_Click(object sender, EventArgs e)
        {
            String filename = String.Empty;
            if ((folderBrowserDialog1.ShowDialog()) == DialogResult.OK)
            {
                System.IO.DirectoryInfo di = new System.IO.DirectoryInfo(folderBrowserDialog1.SelectedPath);
                foreach (System.IO.FileInfo fi in di.GetFiles())  // on récupère tous les fichier
                {
                    if ((fi.Extension == ".bmp") || (fi.Extension == ".png") || (fi.Extension == ".jpg"))
                    {
                        m_filenameList.Add(fi.FullName);
                        listBox1.Items.Add(fi.FullName);
                    }
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (m_filenameList.Count > 0)
            {

                if (m_FormA.isOnTop == true)  // c'est la formA qui est au dessus
                {
                    // on affiche la formB, censée contenir une image
                    // m_FormB.Show();
                    // m_FormB.Select();
                    m_FormB.Show();

                    CrossFade(m_FormA, m_FormB);
                    m_FormB.isOnTop = true;
                    // on cache la formA, chargée avec la nouvelle image, pour le tick d'après...
                    // m_FormA.Hide();
                    m_FormA.isOnTop = false;
                    m_FormA.pictureBox1.Image = Bitmap.FromFile(m_filenameList[m_iterator]);
                    // m_FormA.pictureBox1.Update();
                }
                else // c'est donc FormB qui est au dessus
                {
                    // on affiche la formA, censée contenir une image
                    // m_FormA.Show();
                    // m_FormA.Select();
                    m_FormA.Show();

                    CrossFade(m_FormB, m_FormA);
                    m_FormA.isOnTop = true;
                    // on cache la formA, chargée avec la nouvelle image, pour le tick d'après...
                    // m_FormB.Hide();
                    m_FormB.isOnTop = false;
                    m_FormB.pictureBox1.Image = Bitmap.FromFile(m_filenameList[m_iterator]);
                }
                m_rotationAngle = 0.05F;
                m_iterator++;
                if (m_iterator >= m_filenameList.Count)
                    m_iterator = 0;
            }

        }

        public void CrossFade(Form FromForm, Form ToForm)
        {
            ToForm.Select();            // ToForm est mis au premier plan, on suppose ToForm comme transparent
            // c'est à dire avec Opacity=0
            while (ToForm.Opacity < 1)  // dans cette boucle, on va rendre ToForm progressivement opaque
            {
                ToForm.Opacity += 0.01;
                System.Threading.Thread.Sleep(10);
            }
            FromForm.Opacity = 0;       // FromForm était au second plan. Il est rendu transparent en prévision
        }    

        //static Form GetTopMostForm()
        //{
        //    return Application.OpenForms.Cast<Form>().First(x => x.Focused);
        //    Application.OpenForms.Cast<Form>().First();
        //} 

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Space:
                    if (m_isRunning == true)
                        timer1.Stop();
                    else
                        timer1.Start();
                    m_isRunning = !m_isRunning;
                    break;
                default:
                    break;
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            timer1.Stop();
            m_isRunning = false;
            m_iterator = listBox1.SelectedIndex;
            //pictureBox1.Image = Bitmap.FromFile(m_filenameList[m_iterator]);
            //pictureBox1.Update();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (m_isRunning == true)
            {
                timer1.Stop();
                button2.Text = "Start";
            }
            else
            {
                timer1.Start();
                button2.Text = "Stop";
            }
            m_isRunning = !m_isRunning;
        }


            private void timer2_Tick(object sender, EventArgs e)
            {
                if (m_isRunning == true)
                {
                    if (m_FormB.isOnTop == true)
                    {
                        Graphics gfx = Graphics.FromImage(m_FormB.pictureBox1.Image);
                        gfx.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;

                        gfx.TranslateTransform((float)m_FormB.pictureBox1.Width / 2, (float)m_FormB.pictureBox1.Height / 2);
                        gfx.RotateTransform(m_rotationAngle);
                        gfx.DrawImage(m_FormB.pictureBox1.Image, -m_FormB.pictureBox1.Width / 2, -m_FormB.pictureBox1.Height / 2);

                        m_FormB.pictureBox1.Invalidate();

                    }
                    else
                    {
                        if (m_FormA.pictureBox1.Image != null) // uniquement nécéssaire parce que je n'ai pas soigné ma condition de départ
                        {
                            Graphics gfx = Graphics.FromImage(m_FormA.pictureBox1.Image);
                            gfx.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;

                            gfx.TranslateTransform((float)m_FormA.pictureBox1.Width / 2, (float)m_FormA.pictureBox1.Height / 2);
                            gfx.ScaleTransform(1.0005F, 1.0005F);
                            gfx.DrawImage(m_FormA.pictureBox1.Image, -m_FormA.pictureBox1.Width / 2, -m_FormA.pictureBox1.Height / 2);

                            m_FormA.pictureBox1.Invalidate();
                        }
                    }
                }
            }
    }
}
