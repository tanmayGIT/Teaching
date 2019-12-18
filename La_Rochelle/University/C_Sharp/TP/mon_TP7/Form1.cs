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
        int cell_w ;
        int cell_h;
        int display_h;
        int display_w;
        char car;
        Bitmap m_ColorImage;
        Color m_drawColor;
        
        public Form1()
        {
            InitializeComponent();
            m_ColorImage = new Bitmap(mon_TP7.Properties.Resources.colorpad); 
   m_drawColor = Color.DarkCyan;

        }

    

        private void Form1_Click(object sender, EventArgs e)
        {
     
    
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
                display_w = e.ClipRectangle.Width;
                display_h = e.ClipRectangle.Height;

               cell_w = e.ClipRectangle.Width/13;
                 cell_h = e.ClipRectangle.Height/2;
               
               // Color myColor = Color.DarkCyan;
                 Graphics gfx = Graphics.FromImage(m_ColorImage);
                 SolidBrush brush = new SolidBrush(m_drawColor);
                 gfx.FillRectangle(brush, 0, 0, m_ColorImage.Width, m_ColorImage.Height);
                 couleurToolStripMenuItem.Image = m_ColorImage;

                Pen drawPen = new System.Drawing.Pen(m_drawColor);
                Rectangle textRect = new Rectangle();
                StringFormat format = new StringFormat();
                format.LineAlignment = StringAlignment.Center;
                format.Alignment = StringAlignment.Center;
       //         e.Graphics.DrawRectangle(drawPen, new Rectangle(10, 50, e.ClipRectangle.Width-1, e.ClipRectangle.Height-1));
                e.Graphics.DrawLine(drawPen, 0, e.ClipRectangle.Height / 2, e.ClipRectangle.Width, e.ClipRectangle.Height/2);
                textRect.Size = new Size(cell_w, cell_h);
  
                for (int i = 0; i < 13; i++)
                   {
                    char letter = Convert.ToChar(Convert.ToInt16('A') + i);
                    textRect.Location = new Point(cell_w * i, 0); 
                    e.Graphics.DrawString(letter.ToString(), DefaultFont, brush, textRect, format);
                    letter = Convert.ToChar(Convert.ToInt16(letter) + 13);
                    textRect.Location = new Point(cell_w * i, cell_h);
                    e.Graphics.DrawString(letter.ToString(), DefaultFont, brush, textRect, format);
                    e.Graphics.DrawLine(drawPen, cell_w * i, 0, cell_w * i,e.ClipRectangle.Height );
     
                   
                  }

            }
        }

        private void dessinToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            this.Invalidate();

        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
    
         
           if (e.Button == MouseButtons.Right)
            {
                int x = e.Location.X;
                int y = e.Location.Y;
                car = Convert.ToChar(Convert.ToInt32('A') + x / cell_w + (y / cell_h)*13);
                dernierCaractèreToolStripMenuItem.Text = dernierCaractèreToolStripMenuItem.Text.Remove(dernierCaractèreToolStripMenuItem.Text.Length - 1) + car.ToString();
                Help.ShowHelp(this, "restos.chm", HelpNavigator.KeywordIndex, car.ToString());
            }    
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyData == Keys.F1)
                Help.ShowHelp(this, "restos.chm", HelpNavigator.KeywordIndex, car.ToString());
 

        }

        private void couleurToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.colorDialog1.ShowDialog();
             m_drawColor = this.colorDialog1.Color;

   
            this.Invalidate();

        }



 
    }
}
