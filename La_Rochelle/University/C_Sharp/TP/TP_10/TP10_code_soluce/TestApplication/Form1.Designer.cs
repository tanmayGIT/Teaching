﻿namespace TestApplication
{
    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.juveniaControl2 = new JuveniaLib.JuveniaControl();
            this.juveniaControl1 = new JuveniaLib.JuveniaControl();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(138, 246);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(39, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "PARIS";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(411, 246);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(66, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "NEW-YORK";
            // 
            // juveniaControl2
            // 
            this.juveniaControl2.Location = new System.Drawing.Point(298, 12);
            this.juveniaControl2.m_Offset = System.TimeSpan.Parse("20:00:00");
            this.juveniaControl2.Name = "juveniaControl2";
            this.juveniaControl2.Size = new System.Drawing.Size(228, 218);
            this.juveniaControl2.TabIndex = 1;
            // 
            // juveniaControl1
            // 
            this.juveniaControl1.Location = new System.Drawing.Point(28, 12);
            this.juveniaControl1.m_Offset = System.TimeSpan.Parse("00:00:00");
            this.juveniaControl1.Name = "juveniaControl1";
            this.juveniaControl1.Size = new System.Drawing.Size(228, 218);
            this.juveniaControl1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(578, 286);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.juveniaControl2);
            this.Controls.Add(this.juveniaControl1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private JuveniaLib.JuveniaControl juveniaControl1;
        private JuveniaLib.JuveniaControl juveniaControl2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

