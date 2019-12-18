using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Circles
{
    class Circle
    {
        public Point m_center;
        public int m_radius;
        public Circle(Point center)
        {
            m_center = center;
            m_radius = 0;
        }
    }
}
