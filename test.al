int x4[100];
int y,z,A[100],t;


int f ( int z)
  begin

   write "inside f";
    write z;
     return z;
  end

void main(void) begin
   int g;
    g=f(2);
    write g;
    begin
  int x[5];
  int i;
   i=0;
  while i < 5 do
   begin
      write "enter X";
      read x[i];
      i = i + 1;
   end
 
   i=0;

  while (i < 5) do
   begin
      write x[i] * x[i];
      i = i + 1;
      
   end

    begin
  write "enter X";
  read t;
  write " x is ";
  write t;

end 
end
end
