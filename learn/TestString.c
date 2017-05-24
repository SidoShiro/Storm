CQUAINTANCE
strcmp
(s0, s1)
	compares two arrays in the lexicographic ordering similar to
	memcmp
	, but may not take some language specialties into account. The compar-
	ison stops at the first
	0
	-character that is encountered in either
	s0
	or
	s1
	.  Again,
	both parameters have to be
	0
	-terminated.
strcoll
(s0, s1)
	compares two arrays in the lexicographic ordering respecting
	language specific environment settings. We will learn how to properly ensure to
	set this in Section 8.5.
strchr
(s, c)
	is similar to
	memchr
	, only that the string
	s
	must be
	0
	-terminated.
strspn
(s0, s1)
	returns the number of initial characters in
	s0
	that also appear
	in
	s1
	.
strcspn
(s0, s1)
	returns the number of initial characters in
	s0
	that do not appear
	in
	s1
	.
	Rule 1.6.1.16
	Using a string function with a non-string has undefined behavior.
	In real life, common symptoms for such a misuse may be:
long times for
strlen
or similar scanning functions because they don’t encounter
a
0
-character
segmentation violations because such functions try to access elements after the
boundary of the array object
seemingly random corruption of data because the functions write data in places
where they are not supposed to.
In other words, be careful, and make sure that all your strings really are strings.  If your
platform already supports this, use the functions with bounds checking that were introduce
with C11. There are
strnlen_s
and
strcpy_s
that additionally deal with the maximum length
of their string parameters.
[Exs 30]
The following is an example that uses many of the features that we talked about.
L
ISTING
1.2.  copying a string
1
# i n c l u d e
<string.h>
2
# i n c l u d e
<stdio.h>
3
i n t   main
(
 i n t
 argc,
 c h a r
 *
 * argv[argc+1]) {
	* 4
		* s i z e _ t    c o n s t
		* len =
		* s t r l e n
		* (argv[0]); // compute the length
	* 5
		* c h a r
		* name[len+1];                   // create VLA
	* 6
		*// ensure place for 0
		7
		memcpy
		(name, argv[0], len);         // copy the name
	8
		name[len] = 0;                      // ensure 0 character
	9
		i f
		(!
		 s t r c m p
		 (name, argv[0])) {
			10
				p r i n t f
				("program
				 name
				 \"%s\"
				 successfully
				 copied\n",
				 11
				 name);
			12
		}
	e l s e
	{
		13
			p r i n t f
			("coying
			 %s
			 leads
			 to
			 different
			 string
			 %s\n",
			 14
			 argv[0], name);
		15
	}
	16
}
