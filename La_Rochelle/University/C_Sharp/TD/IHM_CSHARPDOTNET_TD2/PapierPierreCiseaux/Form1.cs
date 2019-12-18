using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace PierrePapierCiseaux
{
    public partial class Form1 : Form
    {
        private Random myRandom;
        private Weapon[] weaponTab;
        public Form1()
        {
            InitializeComponent();
            weaponTab = new Weapon[2];
            myRandom = new Random();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private Weapon RandomWeapon(int player)
        {

            if (player == 1)
            {
                pictureBoxPaper.Visible = pictureBoxRock.Visible = false;
                pictureBoxScissors.Visible = pictureBoxWell.Visible = false;
                // switch (myRandom.Next(1, 5)) pour la version avec puits
                switch (myRandom.Next(1, 4))
                {
                    case 1:
                        pictureBoxPaper.Visible = true;
                        return new Paper();
                    case 2:
                        pictureBoxScissors.Visible = true;
                        return new Scissors();
                    case 3:
                        pictureBoxRock.Visible = true;
                        return new Rock();
                    default:
                        pictureBoxWell.Visible = true;
                        return new Well();
                }
            }
            else // pour une variante à plus de deux joueurs... pour tester
            {

                pictureBoxPaper2.Visible = pictureBoxRock2.Visible = false;
                pictureBoxScissors2.Visible = pictureBoxWell2.Visible = false;
                // switch (myRandom.Next(1, 5)) pour la version avec puits
                switch (myRandom.Next(1, 4))
                {
                    case 1:
                        pictureBoxPaper2.Visible = true;
                        return new Paper();
                    case 2:
                        pictureBoxScissors2.Visible = true;
                        return new Scissors();
                    case 3:
                        pictureBoxRock2.Visible = true;
                        return new Rock();
                    default:
                        pictureBoxWell2.Visible = true;
                        return new Well();
                }
            }
        }

        private Weapon RandomWeaponWithAnimation(int player)
        {
            pictureBoxPaper.Visible = pictureBoxRock.Visible = false;
            pictureBoxScissors.Visible = pictureBoxPaper.Visible = false;
            pictureBoxScissors.Visible = pictureBoxScissors.Visible = false;
            pictureBoxScissors.Visible = pictureBoxWell.Visible = false;
            // switch (myRandom.Next(1, 5)) pour la version avec puits
            for (int i = 0; i < 10; i++) // ANIMATION
            {

                switch (myRandom.Next(1, 4))
                {

                    case 1:
                        pictureBoxPaper.Visible = true;
                        break;
                    case 2:
                        pictureBoxScissors.Visible = true;
                        break;
                    case 3:
                        pictureBoxRock.Visible = true;
                        break;
                    default:
                        break;
                }
                Refresh();
                System.Threading.Thread.Sleep(50 + 25 * i);
                pictureBoxPaper.Visible = pictureBoxRock.Visible = false;
                pictureBoxScissors.Visible = pictureBoxPaper.Visible = false;
                pictureBoxScissors.Visible = pictureBoxScissors.Visible = false;
            }

            switch (myRandom.Next(1, 4))
            {
                case 1:
                    pictureBoxPaper.Visible = true;
                    return new Paper();
                case 2:
                    pictureBoxScissors.Visible = true;
                    return new Scissors();
                case 3:
                    pictureBoxRock.Visible = true;
                    return new Rock();
                default:
                    pictureBoxWell.Visible = true;
                    return new Well();
            }
        }


        private void button_Click(object sender, EventArgs e)
        {
            // ici on essaye de recuperer la classe a partir du lable du bouton
            string className = ((ButtonBase)sender).Text;
            Type CAType = Type.GetType("PierrePapierCiseaux." + className); // on accolle le namespace au nom de la classe
            var myObj = Activator.CreateInstance(CAType); // et on cree un objet de la classe

            textBox1.Text = "Wait...";
            weaponTab[0] = (Weapon)myObj;
            // weaponTab[1] = RandomWeapon(1);
            weaponTab[1] = RandomWeaponWithAnimation(1);
            if (weaponTab[0] == weaponTab.Max())
                // if (weaponTab[1] == weaponTab.Max()) // ca ne marche pas, comparaison de références
                if (weaponTab[1].CompareTo(weaponTab.Max()) == 0)
                    textBox1.Text = "null";
                else
                    textBox1.Text = "I win";
            else
                textBox1.Text = "Computer Wins";
        }

        // on peut le faire avec un callback différent pour chaque bouton

        //private void buttonPaper_Click(object sender, EventArgs e)
        //{
        //    weaponTab[0] = new Paper();
        //    weaponTab[1] = RandomWeapon(1);
        //    weaponTab[2] = RandomWeapon(2);
        //    if (weaponTab[0] == weaponTab.Max())
        //        if (weaponTab[1] == weaponTab.Max()) // ca ne marche pas, comparaison de références
        //            if (weaponTab[1].CompareTo(weaponTab.Max()) == 0)
        //                textBox1.Text = "null";
        //            else
        //                textBox1.Text = "I win";
        //        else
        //            textBox1.Text = "Computer Wins";
        //}

        //private void buttonRock_Click(object sender, EventArgs e)
        //{
        //    weaponTab[0] = new Rock();
        //    weaponTab[1] = RandomWeapon(1);
        //    weaponTab[2] = RandomWeapon(2);
        //    if (weaponTab[0] == weaponTab.Max())
        //        if (weaponTab[1].CompareTo(weaponTab.Max()) == 0)
        //            textBox1.Text = "null";
        //        else
        //            textBox1.Text = "I win";
        //    else
        //        textBox1.Text = "Computer Wins";
        //}

        //private void buttonScissors_Click(object sender, EventArgs e)
        //{
        //    weaponTab[0] = new Scissors();
        //    weaponTab[1] = RandomWeapon(1);
        //    weaponTab[2] = RandomWeapon(2);
        //    if (weaponTab[0] == weaponTab.Max())
        //        if (weaponTab[1].CompareTo(weaponTab.Max()) == 0)
        //            textBox1.Text = "null";
        //        else
        //            textBox1.Text = "I win";
        //    else
        //        textBox1.Text = "Computer Wins";
        //}

        //private void buttonWell_Click(object sender, EventArgs e)
        //{
        //    weaponTab[0] = new Well();
        //    weaponTab[1] = RandomWeapon(1);
        //    weaponTab[2] = RandomWeapon(2);
        //    if (weaponTab[0] == weaponTab.Max())
        //        if (weaponTab[1].CompareTo(weaponTab.Max()) == 0)
        //            textBox1.Text = "null";
        //        else
        //            textBox1.Text = "I win";
        //    else
        //        textBox1.Text = "Computer Wins";
        //}
    }


    public abstract class Weapon : IComparable
    {
        public abstract int CompareTo(object obj);
    }

    public class Paper : Weapon
    {
        public string StringData { get; set; }
        public override int CompareTo(object o)
        {
            if (o is Paper)
                return 0;
            else if ((o is Rock) || (o is Well))
                return 1;
            return -1;
        }
    }

    public class Rock : Weapon
    {
        public string StringData { get; set; }
        public override int CompareTo(object o)
        {
            if (o is Rock)
                return 0;
            else if (o is Scissors)
                return 1;
            return -1;
        }
    }

    public class Scissors : Weapon
    {
        public string StringData { get; set; }
        public override int CompareTo(object o)
        {
            if (o is Scissors)
                return 0;
            else if (o is Paper)
                return 1;
            return -1;
        }
    }

    public class Well : Weapon
    {
        public override int CompareTo(object o)
        {
            if (o is Well)
                return 0;
            else if ((o is Rock) || (o is Scissors))
                return 1;
            return -1;
        }
    }
}
