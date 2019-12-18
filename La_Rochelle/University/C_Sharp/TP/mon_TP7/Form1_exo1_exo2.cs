using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
namespace mon_TP7
{
    public partial class Form1 : Form
    {

        private Button m_button1 = new Button();
        private Button m_button2 = new Button();
        private bool m_dopaint;

        public Form1()
        {
            InitializeComponent();

        }

    

        private void Form1_Click(object sender, EventArgs e)
        {
         //   this.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        /*    m_button1.Text = "Paint";
            m_button1.BackColor = Color.DarkGray;
            m_button1.Location = new System.Drawing.Point(90, 25);
            Controls.Add(m_button1);

            m_button1.Click += new EventHandler(m_button1_Click);

            m_button2.Text = "Clear";
            m_button2.BackColor = Color.DarkGray;
            m_button2.Location = new System.Drawing.Point(190, 25);
            Controls.Add(m_button2);

            m_button2.Click += new EventHandler(m_button2_Click);*/
        }

/*        void m_button2_Click(object sender, EventArgs e)
        {
            m_dopaint = false;
            Invalidate();
        }

        void m_button1_Click(object sender, EventArgs e)
        {
            m_dopaint = true;
            Invalidate();
        }
        */
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            if (dessinToolStripMenuItem1.Checked == true)
            {
                Color myColor = Color.DarkCyan;
                Pen drawPen = new System.Drawing.Pen(myColor);
                Rectangle textRect = new Rectangle();
                StringFormat format = new StringFormat();
                format.LineAlignment = StringAlignment.Center;
                format.Alignment = StringAlignment.Center;
                e.Graphics.DrawRectangle(drawPen, new Rectangle(50, 50, 200, 200));
                e.Graphics.DrawLine(drawPen, 150, 50, 150, 250);
                e.Graphics.DrawLine(drawPen, 50, 150, 250, 150);
                textRect.Location = new Point(50, 50);
                textRect.Size = new Size(100, 100);
                char letter = '1';
                e.Graphics.DrawString(letter.ToString(), DefaultFont, Brushes.Red, textRect, format);
            }
        }

        private void dessinToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.Invalidate();

        }



 
    }
}
