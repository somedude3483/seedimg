uchar clamp(float i){
    if(i > 255.0f)
        return 255;
    else if(i < 0.0f)
        return 0;
    else
        return (uchar)i;
}

__kernel void rotate_hue(float16 hue_kernel, __global uchar4* inp_pix, __global uchar4* res_pix, ulong amt_pixels) {
      int num = get_global_id(0);
      if(num >= amt_pixels)
          return;
      
	  res_pix[num].x = clamp(
                    hue_kernel.s0 * inp_pix[num].x +
                    hue_kernel.s1 * inp_pix[num].y +
                    hue_kernel.s2 * inp_pix[num].z
                  );
      res_pix[num].y = clamp(
                    hue_kernel.s3 * inp_pix[num].x +
                    hue_kernel.s4 * inp_pix[num].y +
                    hue_kernel.s5 * inp_pix[num].z
                  );
      res_pix[num].z = clamp(
                    hue_kernel.s6 * inp_pix[num].x +
                    hue_kernel.s7 * inp_pix[num].y +
                    hue_kernel.s8 * inp_pix[num].z
                  );
}
