using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace RobotControl
{
    public partial class Form1 : Form
    {
        public float angle1, angle2, angle3;
        Matrix matrix1,matrix2, matrix3;
        public Rectangle UpperArm = new Rectangle(0, -1, 75, 3);
        public Rectangle LowerArm = new Rectangle(0, -1, 50, 3);
        public Rectangle Wrist = new Rectangle(0, -1, 20, 3);
        public Rectangle Connexion = new Rectangle(-4, -4, 9, 9);
        public Pen UpperArmPen, LowerArmPen, WristPen;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            angle1 = -35.0f;
            angle2 = 12f;
            angle3 = 6.5f;
            UpperArmPen = new Pen(Color.Blue);
            LowerArmPen = new Pen(Color.Blue);
            WristPen = new Pen(Color.Blue);
            matrix1 = new Matrix();
            matrix2 = new Matrix();
            matrix3 = new Matrix();
            this.picCanvas.MouseWheel += new MouseEventHandler(picCanvas_MouseWheel);


      }

        private void picCanvas_MouseWheel(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            ///process mouse event
            if (WristPen == Pens.Red)
            {
                angle3 += (e.Delta/10);
            }
            if (LowerArmPen == Pens.Red)
            {
                angle2 += (e.Delta/10);
            }
            if (UpperArmPen == Pens.Red)
            {
                angle1 += (e.Delta/10);
            }
            picCanvas.Refresh();
        }
  

        private void DrawRobotArm(Graphics gr)
        {
            const int UpperArmLength = 75;
            const int LowerArmLength = 50;
            const int WristLength = 20;

            gr.SmoothingMode = SmoothingMode.AntiAlias;
            gr.Clear(picCanvas.BackColor);
            matrix1.Reset();
            matrix2.Reset();
            matrix3.Reset();
            // For each stage in the arm, draw and then *prepend* the
            // new transformation to represent the next arm in the sequence.

            // Translate to center of form.
            float cx = picCanvas.ClientSize.Width / 2;
            float cy = picCanvas.ClientSize.Height / 2;
            gr.TranslateTransform(cx, cy);

            // Draw the shoulder centered at the origin.
            gr.DrawEllipse(Pens.Green, Connexion);

            // Rotate at the shoulder.
            // (Negative to make the angle increase counter-clockwise).
            gr.RotateTransform(angle1, MatrixOrder.Prepend);

            //matrix1.Rotate(-angle1);
            //matrix1.Translate(-cx, -cy);

            matrix1.Translate(cx, cy);
            matrix1.Rotate(angle1);
            matrix2 = matrix1.Clone();
            matrix1.Invert();

            // Draw the first arm.
            gr.DrawRectangle(UpperArmPen, UpperArm);

            // Translate to the end of the first arm.
            gr.TranslateTransform(UpperArmLength, 0, MatrixOrder.Prepend);

            // Draw the elbow.
            gr.DrawEllipse(Pens.Green, Connexion);

            // Rotate at the elbow.
            gr.RotateTransform(angle2, MatrixOrder.Prepend);

            //matrix2.Rotate(-angle2);
            //matrix2.Translate(-UpperArmLength, 0);
            //matrix2.Multiply(matrix1);

            matrix2.Translate(UpperArmLength, 0);
            matrix2.Rotate(angle2);
            matrix3 = matrix2.Clone();
            matrix2.Invert();

            // Draw the second arm.
            gr.DrawRectangle(LowerArmPen, 0, -1, LowerArmLength, 3);

            // Translate to the end of the second arm.
            gr.TranslateTransform(LowerArmLength, 0, MatrixOrder.Prepend);

            // Draw the wrist.
            gr.DrawEllipse(Pens.Green, Connexion);

            // Rotate at the wrist.
            gr.RotateTransform(angle3, MatrixOrder.Prepend);

            //matrix3.Rotate(-angle3);
            //matrix3.Translate(-LowerArmLength, 0);
            //matrix3.Multiply(matrix2);

            matrix3.Translate(LowerArmLength, 0);
            matrix3.Rotate(angle3);
            matrix3.Invert();

            // Draw the third arm.
            gr.DrawRectangle(WristPen, 0, -1, WristLength, 3);
        }

        private void picCanvas_Paint(object sender, PaintEventArgs e)
        {
            DrawRobotArm(e.Graphics);
        }

        private void Form1_Click(object sender, EventArgs e)
        {

        }

        private void picCanvas_Click(object sender, EventArgs e)
        {
            picCanvas.Focus();
            Point[] loc = new Point[1];
            loc[0] = ((MouseEventArgs)e).Location;
            matrix1.TransformPoints(loc);
            if (UpperArm.Contains(loc[0]))
            {
                UpperArmPen = Pens.Red;
                LowerArmPen = WristPen = Pens.Blue;
                picCanvas.Refresh();
                return;
            }
            loc[0] = ((MouseEventArgs)e).Location;
            matrix2.TransformPoints(loc);
            if (LowerArm.Contains(loc[0]))
            {
                LowerArmPen = Pens.Red;
                UpperArmPen = WristPen = Pens.Blue;
                picCanvas.Refresh();
                return;
            }
            loc[0] = ((MouseEventArgs)e).Location;
            matrix3.TransformPoints(loc);
            if (Wrist.Contains(loc[0]))
            {
                WristPen = Pens.Red;
                UpperArmPen = LowerArmPen =Pens.Blue;
                picCanvas.Refresh();
                return;
            }
        }
    }
}
