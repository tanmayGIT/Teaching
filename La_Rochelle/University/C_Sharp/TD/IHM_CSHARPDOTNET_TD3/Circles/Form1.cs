using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Circles
{
    public partial class Form1 : Form
    {
        List<Circle> maListe = new List<Circle>();
        Boolean m_doPaint = false;
        Boolean m_endPaint = false;
        Boolean m_down = false;
     
        public Form1()
        {
         
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (m_doPaint && (maListe.Count > 0))
            {
                // compute radius
                Point center = maListe.Last().m_center;
                double dRadius = System.Math.Pow(e.Y - center.Y, 2) + System.Math.Pow(e.X - center.X, 2);
                int iRadius = (int)System.Math.Sqrt(dRadius);
                maListe.Last().m_radius = iRadius;
                // draw circle
                Graphics grx = this.CreateGraphics();
                grx.Clear(SystemColors.Window);
                Rectangle boundingRect = new Rectangle(center.X - iRadius, center.Y - iRadius, 2 * iRadius, 2 * iRadius);
                grx.DrawArc(Pens.Black, boundingRect, 0, 360);
            }
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
        //    m_down = true; 
            if (!m_endPaint)
            {
                m_doPaint = true;
                Circle newCircle = new Circle(new Point(e.X, e.Y));
                maListe.Add(newCircle);
            }
            else
            {
                for (int i = 0; i < maListe.Count; i++)
                {
                    double distance = (int)System.Math.Sqrt(System.Math.Pow(maListe[i].m_center.X - e.X, 2) + System.Math.Pow(maListe[i].m_center.Y - e.Y, 2));
                    if (distance <= maListe[i].m_radius)
                    {
                        Rectangle boundingRect = new Rectangle(maListe[i].m_center.X - 2*maListe[i].m_radius, maListe[i].m_center.Y - 2* maListe[i].m_radius, 2*2 * maListe[i].m_radius, 2*2 * maListe[i].m_radius);
                        Graphics grx = this.CreateGraphics(); 
                        grx.DrawArc(Pens.Black, boundingRect, 0, 360);
                       grx.FillEllipse(new SolidBrush(Color.Red), boundingRect);
                    }
                }
            }

        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {

            m_doPaint = false;
           if(m_endPaint) this.Invalidate();
   
   }



        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.D)
            {
                this.Invalidate();
                m_endPaint = true;
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {

         if(  maListe.Count > 0)
       {
 
            for (int i = 0; i < maListe.Count; i++)
            {
                Rectangle boundingRect = new Rectangle(maListe[i].m_center.X - maListe[i].m_radius, maListe[i].m_center.Y - maListe[i].m_radius, 2 * maListe[i].m_radius, 2*maListe[i].m_radius);
                e.Graphics.DrawArc(Pens.Black, boundingRect, 0, 360);
            }


       }

        
        }


    }
}