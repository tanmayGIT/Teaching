using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication8
{
    public partial class Form1 : Form
    {
        DateTime myTime = DateTime.Now;
        public Form1()
        {
            InitializeComponent();

            // ajout manuel listboxzone2

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap("timezone_none.png");
            listBoxZones.Items.Add(new myTimeZoneDescription("Paris, Berlin, Rome", 1, 0));
            listBoxZones.Items.Add(new myTimeZoneDescription("Londres, Dublin", -1, -30));
            listBoxZones.Items.Add(new myTimeZoneDescription("a, b", -2, -30));
            listBoxZones.Items.Add(new myTimeZoneDescription("x,y", +10, 00));
            textBox1.Text = myTime.ToString(); // Convert.ToString(myTime.Hour % 12);
        }

        private void listBoxZones_SelectedIndexChanged(object sender, EventArgs e)
        {
            myTimeZoneDescription toto  = listBoxZones.Items[listBoxZones.SelectedIndex] as myTimeZoneDescription;
            TimeSpan t = toto.GetOffset;
            String s = t.ToString();
            s = s.Replace(':', '_');
            s = "timezone_" + s + ".png";
            try
            {
                pictureBox1.Image = new Bitmap(s);
            }
            catch
            {}
        }

        private void button1_Click(object sender, EventArgs e)
        {
                listBoxZones.Sorted = true;   // tri avec la conversion directe tostring

                // pour trier selon la localisation
            // cration array
                myTimeZoneDescription[] tab = new myTimeZoneDescription[listBoxZones.Items.Count];
            // copy to array
                listBoxZones.Items.CopyTo(tab, 0);
            // tri array (use CompareTo)
                Array.Sort(tab);
            // on rempli le second listbox
                listBoxZones2.Items.AddRange(tab);

            
        }
    }



    public class myTimeZoneDescription : IComparable<myTimeZoneDescription>

    {
        private String m_Location;
        private TimeSpan m_Offset;
        public TimeSpan GetOffset
        {
            get { return m_Offset; }
        }
        // constructeur
        public myTimeZoneDescription(String loc, int hoffset, int moffset)
        {
            m_Location = loc;
            m_Offset = new TimeSpan(hoffset, moffset, 0);
        }
        // surcharge de ToString()
        public override String ToString()
        {
            if (m_Offset.Ticks < 0)
                return ("(UTC-" + m_Offset.ToString(@"hh\:mm") + ")" + "\t" + m_Location);
            else if (m_Offset.Ticks > 0)
                return ("(UTC+" + m_Offset.ToString(@"hh\:mm") + ')' + '\t' + m_Location);
            else
                return ("(UTC)" + '\t' + '\t' + m_Location);
        }

        public int CompareTo(myTimeZoneDescription other)
        {
            return (this.m_Location.CompareTo(other.m_Location));
        }
    }
}
