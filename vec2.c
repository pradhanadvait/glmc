void glmc_vec2f_from_3f(vec2f dest, vec3f src)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src[i];
	}
}

void glmc_vec2f_from_4f(vec2f dest, vec2f src)
{	
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src[i];
	}
}

void glmc_vec2f_copy(vec2f dest, vec2f src)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src [i];
	}
}

float glmc_vec2f_sqrlength(vec2f vec)
{
	return 4.0f;
}

float glmc_vec2f_length(vec2f vec)
{
	return 2.0f;
}

int  glmc_vec2f_is_normalized(vec2f src)
{
	int norm=0;
	for(int i = 0; i < 2; i++)
	{
		norm = src[i] * src[i];
	}
	
	return norm == 1;
}

void glmc_vec2f_normlize(vec2f dest, vec2f src)
{
	int norm=0;
	for(int i = 0; i < 2; i++)
	{
		norm += src[i]*src[i];
	}
	
	for(int i = 0; i < 2; i++)
	{
		vec3f[i] /= norm;
	}		
}

void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b) // dest = src_a + src_b;
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] + src_b[i];
	}

}
void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b) // dest += src_a;
{
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] += src_b[i];
	}
}

void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b) // dest = src_a - src_b;
{	
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] - src_b[i];
	}
}

void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b) // dest -= src_a;
{
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] -= src_b[i];
	}
}

void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b) // dest = src_a * src_b;
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] * src_b[i];
	}
}

void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b) // dest *= src_a;
{
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] *= src_b[i];
	}
}

void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b) // dest = src_a * scalar
{
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] = src_a[i]*src_b;
	}
}

void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b) // dest = src_a / src_b;
{
	if((src_b[0] != 0) && (src_b[1] != 0))
	{
		for(int i = 0; i < 2; i++)
		{
			dest[i] = src_a[i] / src_b[i];
		}
	}
	else
	{
		printf("Cannot Divide by zero!");
		break;
	}
}

void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b) // dest /= src_a;
{
	if((src_b[0] != 0) && (src_b[1] != 0))
	{
		for(int i = 0; i < 2; i++)
		{
			src_dest[i] /= src_b[i];
		}
	}
	else
	{
		printf("Cannot Divide by zero!");
		break;
	}
}

void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b) // dest = src_a / scalar
{
	if(src_b != 0)
	{
		for(int i = 0; i < 2; i++)
		{
			dest[i] = src_a[i] / src_b;
		}
	}
	else
	{
		printf("Cannot Divide by zero!");
		break;
	}
}

void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b) // dest += src_a + src_b;
{
	vec2f vec = [0 0];
	glmc_vec2f_add(vec, src_a, src_b);
	glmc_vec2f_add_dest(dest, vec);
}

void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b) // dest += src_a - src_b;
{
	vec2f vec = [0 0];
	glmc_vec2f_sub(vec, src_a, src_b);
	glmc_vec2f_add_dest(dest, vec);
}

void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b) // dest += src_a * src_b;
{
	vec2f vec = [0 0];
	glmc_vec2f_mul(vec, src_a, src_b);
	glmc_vec2f_add_dest(dest, vec);
}

void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b) // dest -= src_a * src_b;
{
	vec2f vec;
	glmc_vec2f_mul(vec, src_a, src_b);
	glmc_vec2f_sub_dest(dest, vec);
}

float glmc_vec2f_dot(vec2f src_a, vec2f src_b)
{
	return src_a[0]*src_b[0]+src_a[1]*src_b[1];
}
