/*

Implement an efficient serialization and deserialization algorithm for an embedded device. The receiving party may have a different OS and or MCU. Also, consider security and compression. Consider the following:



  1) What are the primitive data types and how are they to be encoded/compressed for 

 serialisation?

 2) Write a serializer function to encode bit32, bit64 and varint primitive type variables

How is the size of a particular variable / field known for deserialisation?
What is the byte ordering convention?
What bit manipulation operations are considered
﻿How is the location (offset) of a particular variable/field known for deserialisation?
  3) What type of objects are being exchanged? Bitmaps, encoded images (X-ray scans,

  Camera etc.), GIS data etc.

4) During serialisation/deserialisation, what are the data transformation algorithms to

 be done on each Octet? Check sums, encryption/decryption? Are there HW 

 accelerators for these? If so, what data paths are needed before SW can access 

 these octets? 

5) How to identify the serialising protocol used (Netstrings, LCM, Protobuffer)



*/