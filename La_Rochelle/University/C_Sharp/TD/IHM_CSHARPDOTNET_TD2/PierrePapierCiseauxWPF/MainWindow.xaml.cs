using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PierrePapierCiseauxWPF
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    ///     

          
        //public static void Refresh(this UIElement uiElement)
        //{
        //    uiElement.Dispatcher.Invoke(System.Windows.Threading.DispatcherPriority.Render, EmptyDelegate);
        //}

    public partial class MainWindow : Window
    {
        private static Action EmptyDelegate = delegate() { };



        private Random myRandom;
        private Weapon[] weaponTab;
        public MainWindow()
        {
            InitializeComponent();
            weaponTab = new Weapon[3];
            myRandom = new Random();
        }





     

        private void button_Click(object sender, EventArgs e)
        {
            // remarquer que c'était ButtonBase.Text en WindowsForm
            // et que cela devient ButtonBase.Name en WPF/XAML
            string className = ((System.Windows.Controls.Primitives.ButtonBase)sender).Name;
            // il faut aussi changer le namespace
            Type CAType = Type.GetType("PierrePapierCiseauxWPF." + className);
            var myObj = Activator.CreateInstance(CAType);

            textBox1.Text = "Wait...";
            weaponTab[0] = (Weapon)myObj;
            weaponTab[1] = RandomWeapon();
            this.Dispatcher.Invoke(System.Windows.Threading.DispatcherPriority.Render, EmptyDelegate);
            if (weaponTab[0] == weaponTab.Max())
                // if (weaponTab[1] == weaponTab.Max()) // ca ne marche pas, comparaison de références
                if (weaponTab[1].CompareTo(weaponTab.Max()) == 0)
                    textBox1.Text = "null";
                else
                    textBox1.Text = "I win";
            else
                textBox1.Text = "Computer Wins";
        }

        // new 2016... effet d'animation lors du tirage aléatoire


        private Weapon RandomWeapon()
        {
            image1.Visibility = System.Windows.Visibility.Hidden;
            image2.Visibility = System.Windows.Visibility.Hidden;
            image3.Visibility = System.Windows.Visibility.Hidden;
            for (int i = 0; i < 10; i++) // ANIMATION
            {
                switch (myRandom.Next(1, 4))
                {
                    case 1:
                        image1.Visibility = System.Windows.Visibility.Visible;
                        break;
                    case 2:
                        image2.Visibility = System.Windows.Visibility.Visible;
                        break;
                    case 3:
                        image3.Visibility = System.Windows.Visibility.Visible;
                        break;
                    default:
                        // pictureBoxWell.Visible = true;
                        break;
                }
                this.Dispatcher.Invoke(System.Windows.Threading.DispatcherPriority.Render, EmptyDelegate);
                //image2.InvalidateVisual();
                //image3.InvalidateVisual();
                //UpdateLayout();
                System.Threading.Thread.Sleep(50 + 25 * i); // slow down more the longer the loop runs
                image1.Visibility = System.Windows.Visibility.Hidden;
                image2.Visibility = System.Windows.Visibility.Hidden;
                image3.Visibility = System.Windows.Visibility.Hidden;
            }
            switch (myRandom.Next(1, 4))  // tirage final
            {
                case 1:
                    image1.Visibility = System.Windows.Visibility.Visible;
                    return new Paper();
                case 2:
                    image2.Visibility = System.Windows.Visibility.Visible;
                    return new Rock();
                case 3:
                    image3.Visibility = System.Windows.Visibility.Visible;
                    return new Scissors();
                default:
                    // pictureBoxWell.Visible = true;
                    return new Well();
            }
        }
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
