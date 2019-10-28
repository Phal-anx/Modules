/*
Posted by scoofy[AT]inf[DOT]elte[DOT]hu at musicdsp.org

modified by Michael Struggl (2018)
*/


class interpolator_linear {
	public:
		interpolator_linear() 
		{ 
			reset_hist();
		}

		// reset history
		void reset_hist() {
			d1 = 0.f;
		}

		// 2x interpolator
		// out: pointer to float[2]
		inline float process2x(float const in, float *out) {
			out[0] = d1 + 0.5f*(in-d1);	// interpolate
			out[1] = in;
			d1 = in; // store delay
			return *out;
		}
		
		// 2x interpolator
		// out: pointer to float[4]
		inline float process2xP(float const *in, float x, float *ot) {
			float dt1 = 0.f;
			float xi = *in-dt1;
				ot[0] = dt1 + x*xi;	// interpolate
				ot[1] = *in;
				dt1 = *in; // store delay
				return *ot;
		}

		// 4x interpolator
		// out: pointer to float[4]
		inline float process4x(float const in, float *out) {
		float y = in-d1;
			out[0] = d1 + 0.25f*y;	// interpolate
			out[1] = d1 + 0.5f*y;
			out[2] = d1 + 0.75f*y;
			out[3] = in;
			d1 = in; // store delay
			return *out;
		}
		
		// 4x interpolator
		// out: pointer to float[4]
		inline double process4xX(double const in, double *out) {
		double y = in-d1;
			out[0] = d1 + 0.25f*y;	// interpolate
			out[1] = d1 + 0.5f*y;
			out[2] = d1 + 0.75f*y;
			out[3] = in;
			d1 = in; // store delay
			return *out;
		}
		
		// 4x interpolator
		// out: pointer to float[4]
		inline float process4xP(float const *in, float x, float *ot) {
			float dt1 = 0.f;
			float xi = *in-dt1;
				ot[0] = dt1 + x*xi;	// interpolate
				ot[1] = dt1 + x*xi;
				ot[2] = dt1 + x*xi;
				ot[3] = *in;
				dt1 = *in; // store delay
				return *ot;
		}
		
		
		// 8x interpolator
		// out: pointer to float[8]
		inline float process8x(float const in, float *out) {
			float y = in-d1;
			out[0] = d1 + 0.125f*y;	// interpolate
			out[1] = d1 + 0.25f*y;
			out[2] = d1 + 0.375f*y;
			out[3] = d1 + 0.5f*y;
			out[4] = d1 + 0.625f*y;
			out[5] = d1 + 0.75f*y;
			out[6] = d1 + 0.875f*y;
			out[7] = in;
			d1 = in; // store delay
			return *out;
		}

		// 16x interpolator
		// out: pointer to float[16]
		inline float process16x(float const in, float *out) {
			float y = in-d1;
			out[0] = d1 + (1.0f/16.0f)*y;	// interpolate
			out[1] = d1 + (2.0f/16.0f)*y;	
			out[2] = d1 + (3.0f/16.0f)*y;	
			out[3] = d1 + (4.0f/16.0f)*y;	
			out[4] = d1 + (5.0f/16.0f)*y;	
			out[5] = d1 + (6.0f/16.0f)*y;	
			out[6] = d1 + (7.0f/16.0f)*y;	
			out[7] = d1 + (8.0f/16.0f)*y;	
			out[8] = d1 + (9.0f/16.0f)*y;	
			out[9] = d1 + (10.0f/16.0f)*y;	
			out[10] = d1 + (11.0f/16.0f)*y;	
			out[11] = d1 + (12.0f/16.0f)*y;	
			out[12] = d1 + (13.0f/16.0f)*y;	
			out[13] = d1 + (14.0f/16.0f)*y;	
			out[14] = d1 + (15.0f/16.0f)*y;	
			out[15] = in;	
			d1 = in; // store delay
			return *out;
		}

		// 32x interpolator
		// out: pointer to float[32]
		inline float process32x(float const in, float *out) {
			float y = in-d1;
			out[0] = d1 + (1.0f/32.0f)*y;	// interpolate
			out[1] = d1 + (2.0f/32.0f)*y;	
			out[2] = d1 + (3.0f/32.0f)*y;	
			out[3] = d1 + (4.0f/32.0f)*y;	
			out[4] = d1 + (5.0f/32.0f)*y;	
			out[5] = d1 + (6.0f/32.0f)*y;	
			out[6] = d1 + (7.0f/32.0f)*y;	
			out[7] = d1 + (8.0f/32.0f)*y;	
			out[8] = d1 + (9.0f/32.0f)*y;	
			out[9] = d1 + (10.0f/32.0f)*y;	
			out[10] = d1 + (11.0f/32.0f)*y;	
			out[11] = d1 + (12.0f/32.0f)*y;	
			out[12] = d1 + (13.0f/32.0f)*y;	
			out[13] = d1 + (14.0f/32.0f)*y;	
			out[14] = d1 + (15.0f/32.0f)*y;	
			out[15] = d1 + (16.0f/32.0f)*y;	
			out[16] = d1 + (17.0f/32.0f)*y;	
			out[17] = d1 + (18.0f/32.0f)*y;	
			out[18] = d1 + (19.0f/32.0f)*y;	
			out[19] = d1 + (20.0f/32.0f)*y;	
			out[20] = d1 + (21.0f/32.0f)*y;	
			out[21] = d1 + (22.0f/32.0f)*y;	
			out[22] = d1 + (23.0f/32.0f)*y;	
			out[23] = d1 + (24.0f/32.0f)*y;	
			out[24] = d1 + (25.0f/32.0f)*y;	
			out[25] = d1 + (26.0f/32.0f)*y;	
			out[26] = d1 + (27.0f/32.0f)*y;	
			out[27] = d1 + (28.0f/32.0f)*y;	
			out[28] = d1 + (29.0f/32.0f)*y;	
			out[29] = d1 + (30.0f/32.0f)*y;	
			out[30] = d1 + (31.0f/32.0f)*y;	
			out[31] = in;	
			d1 = in; // store delay
			return *out;
		}

	private:
		float d1; // previous input
};