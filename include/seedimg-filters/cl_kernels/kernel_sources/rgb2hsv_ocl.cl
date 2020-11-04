inline float fmodulo(float x, float N) {
  return fmod(x, N) + (fmod(x, N) < 0) * N;
}

__kernel void rgb2hsv(__global uchar4* inp_pix, __global uchar4* res_pix) {
      ulong num = get_global_id(0);
      //ulong num = get_global_id(0);
        
        float rp = (float)inp_pix[num].x / 255.0f;
        float gp = (float)inp_pix[num].y / 255.0f;
        float bp = (float)inp_pix[num].z / 255.0f;
        
        float cmax = fmax(rp, fmax(gp, bp));
        float cmin = fmin(rp, fmin(gp, bp));
        
        float delta = cmax - cmin;
        
        
        float h = (rp == cmax) * (30 * fmodulo((gp-bp) / delta, 6.0f)) +
                  (gp == cmax) * (60 * ((bp-rp) / delta + 2)) +
                  (bp == cmax) * (60 * ((rp-gp) / delta + 4));
        
        float s = (cmax > 0) * ((delta/cmax)*100.0f);
        
        float v = (cmax * 100.0f);
        
        res_pix[num].xyz = (uchar)(cmax != 0) * (uchar3)(h,s,v);
}
