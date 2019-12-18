using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace BouncingBall
{
    public partial class Form1 : Form
    {
        Bitmap m_b;
        int dx, dy;   // pour gerer les rebonds, il faut mémoriser le déplacement selon chaque axe
        Point m_p = new Point(0, 0);

        public Form1()
        {
            InitializeComponent();
            // chargement depuis un fichier - il doit se trouver dans le repertoire de l'executable
            // m_b = new Bitmap("ball.bmp");

            // chargement si l'image a été ajouté aux ressources
            m_b = new Bitmap(BouncingBall.Properties.Resources.ball);

            dx = dy = 2;

            Timer t = new Timer();
            t.Interval = 50;
            t.Tick += new EventHandler(t_Tick);
            t.Start();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        void t_Tick(object sender, EventArgs e)
        {
            
            m_p.X += dx;
            m_p.Y += dy;

            // gestion de rebond
            // ATTENTION la largeur et la hauteur de la form inclut les décorations (barre de titre et bordures de la fenetre)
            // il faut utiliser ClientSize


            if (m_p.X < 0)
            {
                m_p.X = 0;
                dx = -dx;
            }
            if (m_p.Y < 0)
            {
                m_p.Y = 0;
                dy = -dy;
            }
            if (m_p.X + m_b.Width > this.ClientSize.Width)
            {
                m_p.X = this.ClientSize.Width - m_b.Width;
                dx = -dx;
            }
            if (m_p.Y + m_b.Height > this.ClientSize.Height)
            {
                m_p.Y = this.ClientSize.Height - m_b.Height;
                dy = -dy;
            }

            Invalidate();
            // Update();
        }

        private void Form1_Paint_1(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImage(m_b, m_p);
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            m_p = ((MouseEventArgs)e).Location;
            Invalidate();
        }
    }
}
