﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace exo2_serialize.cs
{


    [Serializable]
    class Intervalle
    {
        public int m_x;
        public int m_amount;
        public Intervalle(int a, int b)
        {
            m_x = a;
            m_amount = b;
        }
    }


}