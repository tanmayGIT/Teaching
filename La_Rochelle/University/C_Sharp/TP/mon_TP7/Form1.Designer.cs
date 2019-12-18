namespace mon_TP7
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.gcvxToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dessinToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dessinToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.couleurToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dernierCaractèreToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aideToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.gcvxToolStripMenuItem,
            this.dessinToolStripMenuItem,
            this.aideToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(509, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // gcvxToolStripMenuItem
            // 
            this.gcvxToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem});
            this.gcvxToolStripMenuItem.Name = "gcvxToolStripMenuItem";
            this.gcvxToolStripMenuItem.Size = new System.Drawing.Size(50, 20);
            this.gcvxToolStripMenuItem.Text = "Fichier";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(119, 22);
            this.openToolStripMenuItem.Text = "Open..";
            // 
            // dessinToolStripMenuItem
            // 
            this.dessinToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dessinToolStripMenuItem1,
            this.couleurToolStripMenuItem,
            this.dernierCaractèreToolStripMenuItem});
            this.dessinToolStripMenuItem.Name = "dessinToolStripMenuItem";
            this.dessinToolStripMenuItem.Size = new System.Drawing.Size(50, 20);
            this.dessinToolStripMenuItem.Text = "Dessin";
            // 
            // dessinToolStripMenuItem1
            // 
            this.dessinToolStripMenuItem1.Checked = true;
            this.dessinToolStripMenuItem1.CheckOnClick = true;
            this.dessinToolStripMenuItem1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.dessinToolStripMenuItem1.Name = "dessinToolStripMenuItem1";
            this.dessinToolStripMenuItem1.Size = new System.Drawing.Size(179, 22);
            this.dessinToolStripMenuItem1.Text = "Dessin";
            this.dessinToolStripMenuItem1.Click += new System.EventHandler(this.dessinToolStripMenuItem1_Click);
            // 
            // couleurToolStripMenuItem
            // 
            this.couleurToolStripMenuItem.Checked = true;
            this.couleurToolStripMenuItem.CheckOnClick = true;
            this.couleurToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.couleurToolStripMenuItem.Image = global::mon_TP7.Properties.Resources.colorpad;
            this.couleurToolStripMenuItem.Name = "couleurToolStripMenuItem";
            this.couleurToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.couleurToolStripMenuItem.Text = "Couleur";
            this.couleurToolStripMenuItem.Click += new System.EventHandler(this.couleurToolStripMenuItem_Click);
            // 
            // dernierCaractèreToolStripMenuItem
            // 
            this.dernierCaractèreToolStripMenuItem.Name = "dernierCaractèreToolStripMenuItem";
            this.dernierCaractèreToolStripMenuItem.Size = new System.Drawing.Size(179, 22);
            this.dernierCaractèreToolStripMenuItem.Text = "Dernier caractère:  ";
            // 
            // aideToolStripMenuItem
            // 
            this.aideToolStripMenuItem.Alignment = System.Windows.Forms.ToolStripItemAlignment.Right;
            this.aideToolStripMenuItem.Name = "aideToolStripMenuItem";
            this.aideToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.aideToolStripMenuItem.Text = "Aide";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(509, 455);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.MinimumSize = new System.Drawing.Size(400, 200);
            this.Name = "Form1";
            this.Opacity = 0.95D;
            this.Text = "Mon Application TP7";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Click += new System.EventHandler(this.Form1_Click);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.MouseClick += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseClick);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem gcvxToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dessinToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem couleurToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dernierCaractèreToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aideToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dessinToolStripMenuItem1;
        private System.Windows.Forms.ColorDialog colorDialog1;
    }
}

