using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace JuveniaLib
{
    public partial class JuveniaControl : UserControl
    {
        Bitmap m_SecondBitmap, m_MinuteBitmap, m_HourBitmap;
        public TimeSpan m_Offset {get; set;}
  
        public JuveniaControl()
        {
            InitializeComponent();
            m_SecondBitmap = new Bitmap(JuveniaLib.Properties.Resources.SecondDial);
            m_MinuteBitmap = new Bitmap(JuveniaLib.Properties.Resources.MinuteDial);
            m_HourBitmap = new Bitmap(JuveniaLib.Properties.Resources.HourDial);
            m_SecondBitmap.MakeTransparent(Color.White);
            m_MinuteBitmap.MakeTransparent(Color.White);
            m_HourBitmap.MakeTransparent(Color.White);
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.Invalidate();
        }

        private void JuveniaControl_Paint(object sender, PaintEventArgs e)
        {
            Graphics gfx;
            DateTime date1 = DateTime.Now + m_Offset;
            int seconds = date1.Second;
            int minutes = date1.Minute;
            int hour = date1.Hour % 12;

            int xcenter = this.Width / 2;
            int ycenter = this.Height / 2;

            gfx = this.CreateGraphics();
            gfx.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;

            gfx.TranslateTransform(xcenter, ycenter);
            gfx.RotateTransform(((float)hour * 30.0F) + ((float)minutes / 2.0F));
            gfx.DrawImage(m_HourBitmap, -65, -110);


            gfx.ResetTransform();
            gfx.TranslateTransform(xcenter, ycenter);
            gfx.RotateTransform(((float)minutes * 6.0F) + ((float)seconds / 10.0F));
            gfx.DrawImage(m_MinuteBitmap, -49, -79);

            gfx.ResetTransform();
            gfx.TranslateTransform(xcenter, ycenter);  // pour positionner le dessin au bon endroit
            gfx.RotateTransform(((float)seconds * 6.0F));
            gfx.DrawImage(m_SecondBitmap, -35, -49);
        }

        private void JuveniaControl_Load(object sender, EventArgs e)
        {

        }
    }
}
