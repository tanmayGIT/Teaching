using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsSlotMachineStudent
{
    public partial class Form1 : Form
    {
        SpinTextBox spin1;
        // myTrackBar levier;
        myProgressBar monnayeur;
        public Form1()
        {
            InitializeComponent();

            spin1 = new SpinTextBox();
            spin1.Location = new Point(20, 20);
            this.Controls.Add(spin1);

            //levier = new myTrackBar();
            //levier.Location = new Point(400, 20);
            //levier.Size = new Size(30,150);
            //this.Controls.Add(levier);

            monnayeur = new myProgressBar();
            monnayeur.Location = new Point(400, 20);
            monnayeur.Size = new Size(30, 150);

            // valeur positionné à titre indicatif, pour montrer qu'il s'agit bien d'une progressBar vertical
            // au lancement de votre application, le controle doit être vide... 
            monnayeur.Value = 10; 

            this.Controls.Add(monnayeur);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (spin1.Spin(30) == true)   // on invoque la methode spin (bloquante pendant la durée de "rotation")
            {
                textBox1.Text = "You win !";
            }
            else
                textBox1.Text = "You lose";
        }
    }

    class SpinTextBox : TextBox
    {
        private String[] symbols = { "-", "#", "?", "$", "7", "§" };
        private Random rand;

        public SpinTextBox()
        {
            this.rand = new Random();
            this.Text = "---";            // affichage initial
            // choix d'une police de caractere non proportionelle, quelque soit les caracteres, l'espacement est tjs de la meme largeur
            // grande police, caractères gras
            this.Font = new Font("Courier New", 48.0f, FontStyle.Bold);
            this.ReadOnly = true;         // textBox en lecture seule
            // calcul automatique de la taille de la textbox
            using (Graphics g = this.CreateGraphics())
                this.Width = (int)g.MeasureString("---", this.Font).Width;
        }

        // methode provoquant la simulation de la rotation des roues portant les symboles
        public Boolean Spin(int duration)
        {
            Color oldColor;
            String a = "", b = "", c = "";

            // on mémorise la couleur de fond
            oldColor = this.BackColor;
            // le fond devient rouge tant que "les roues tournent"
            this.BackColor = Color.Red;
            for (int i = 0; i < duration; i++)
            {
                System.Threading.Thread.Sleep(30 + 15 * i); // effet de ralentissement, la pause augmente quand i augmente

                if (i < 10)   // la première roue s'arrete apres 10 itérations
                {
                    // symbole recupéré alatoirement, sauf le symbole symbols[0];
                    a = symbols[rand.Next(1, symbols.Length)];
                }

                if (i < 15)   // la seconde roue s'arrete apres 15 itérations
                {
                    b = symbols[rand.Next(1, symbols.Length)];
                }

                // la derniere roue continue plus longtemps, ce qui ménage le suspens !
                c = symbols[rand.Next(1, symbols.Length)];

                // on combine les symboles pour affichage
                this.Text = a + b + c;
                this.Refresh();
            }
            // fin de la rotation des 3 roues, on restore la couleur de fond
            this.BackColor = oldColor;
            this.Refresh();

            // test simple pour savoir si l'on a gagné  ou non.
            if (a == b && b == c)   // 3 symboles identiques
                return true;
            else
                return false;
        }
    }

    //// partie 2, groupes du lundi
    //class myTrackBar : TrackBar
    //{
    //    public myTrackBar()
    //    {
    //        this.Orientation = Orientation.Vertical;
    //        this.TickStyle = TickStyle.None;
    //    }
    //}


    // partie 2 groupe du mercredi
    class myProgressBar : ProgressBar
    {
        public myProgressBar()
        {
        }
        // laisser cette property, elle permet de tracer l'objet verticalement.
        protected override CreateParams CreateParams
        {
            get
            {
                // Avoid CA2122
                new System.Security.Permissions.SecurityPermission(System.Security.Permissions.SecurityPermissionFlag.UnmanagedCode).Demand();

                CreateParams cp = base.CreateParams;
                cp.Style |= 0x04;
                return cp;
            }
        }
    }

}
