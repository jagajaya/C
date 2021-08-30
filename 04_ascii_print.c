/********************************************
NAME		: Jagajeevan.S
DATE		: 01.06.2021
DESCRIPTION	: To print all ascii characters
OUTPUT		:

Oct	Dec	Hex	Char
________________________________________

000	0	00	Non printable
001	1	01	Non printable
002	2	02	Non printable
003	3	03	Non printable
004	4	04	Non printable
005	5	05	Non printable
006	6	06	Non printable
007	7	07	Non printable
010	8	08	Non printable
011	9	09	Non printable
012	10	0A	Non printable
013	11	0B	Non printable
014	12	0C	Non printable
015	13	0D	Non printable
016	14	0E	Non printable
017	15	0F	Non printable
020	16	10	Non printable
021	17	11	Non printable
022	18	12	Non printable
023	19	13	Non printable
024	20	14	Non printable
025	21	15	Non printable
026	22	16	Non printable
027	23	17	Non printable
030	24	18	Non printable
031	25	19	Non printable
032	26	1A	Non printable
033	27	1B	Non printable
034	28	1C	Non printable
035	29	1D	Non printable
036	30	1E	Non printable
037	31	1F	Non printable
040	32	20	 
041	33	21	!
042	34	22	"
043	35	23	#
044	36	24	$
045	37	25	%
046	38	26	&
047	39	27	'
050	40	28	(
051	41	29	)
052	42	2A	*
053	43	2B	+
054	44	2C	,
055	45	2D	-
056	46	2E	.
057	47	2F	/
060	48	30	0
061	49	31	1
062	50	32	2
063	51	33	3
064	52	34	4
065	53	35	5
066	54	36	6
067	55	37	7
070	56	38	8
071	57	39	9
072	58	3A	:
073	59	3B	;
074	60	3C	<
075	61	3D	=
076	62	3E	>
077	63	3F	?
100	64	40	@
101	65	41	A
102	66	42	B
103	67	43	C
104	68	44	D
105	69	45	E
106	70	46	F
107	71	47	G
110	72	48	H
111	73	49	I
112	74	4A	J
113	75	4B	K
114	76	4C	L
115	77	4D	M
116	78	4E	N
117	79	4F	O
120	80	50	P
121	81	51	Q
122	82	52	R
123	83	53	S
124	84	54	T
125	85	55	U
126	86	56	V
127	87	57	W
130	88	58	X
131	89	59	Y
132	90	5A	Z
133	91	5B	[
134	92	5C	\
135	93	5D	]
136	94	5E	^
137	95	5F	_
140	96	60	`
141	97	61	a
142	98	62	b
143	99	63	c
144	100	64	d
145	101	65	e
146	102	66	f
147	103	67	g
150	104	68	h
151	105	69	i
152	106	6A	j
153	107	6B	k
154	108	6C	l
155	109	6D	m
156	110	6E	n
157	111	6F	o
160	112	70	p
161	113	71	q
162	114	72	r
163	115	73	s
164	116	74	t
165	117	75	u
166	118	76	v
167	119	77	w
170	120	78	x
171	121	79	y
172	122	7A	z
173	123	7B	{
174	124	7C	|
175	125	7D	}
176	126	7E	~
177	127	7F	Non printable

*********************************************/
//  To print all ascii characters

#include<stdio.h>

int main()
{
	printf("Oct\tDec\tHex\tChar\n");	// printing tables like format
	printf("________________________________________");
	printf("\n");
		
	for (int i=0;i<=127;i++)	// to considering all ascii values in for loop
	{
		printf("\n");
		
		if (i > 32 && i < 127)	// for printable characters
			printf("%03o\t%d\t%X\t%c",i, i, i, i);
			
		else if (i <= 31 || i == 127) // for non printable characters
		{
			printf("%03o\t%d\t%02X",i, i, i);
			printf("\tNon printable");
		}
		else if (i == 32)
		{
			printf("%03o\t%d\t%02X",i, i, i);
			printf("\t ");
		}
		
	}
	printf("\n");
	
	return 0;
}
