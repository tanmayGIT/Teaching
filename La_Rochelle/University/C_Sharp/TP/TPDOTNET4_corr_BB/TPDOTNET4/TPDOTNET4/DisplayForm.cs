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
    public partial class DisplayForm : Form
    {
        public Boolean isOnTop = false;
        public DisplayForm()
        {
            InitializeComponent();
        }

        private void DisplayForm_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
                Application.Exit();
        }
    }
}
