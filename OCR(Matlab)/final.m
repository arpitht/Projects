x=input('Enter image name: ','s');
TestIm=imread(x);

%Convert to gray scale
if size(TestIm,3)==3 %RGB image
    TestIm = rgb2gray(TestIm);
end
%Convert to binary image
threshold = graythresh(TestIm);
TestIm =~im2bw(TestIm,threshold);


%Remove Salt and paper noise
%TestIm = medfilt2(TestIm);

%BW = edge(TestIm,'sobel'); %finding edges 
%[imx,imy]=size(BW);
%msk=[0 0 0 0 0;
%     0 1 1 1 0;
%     0 1 1 1 0;
 %    0 1 1 1 0;
 %    0 0 0 0 0;];
%B=conv2(double(BW),double(msk)); %Smoothing  image to reduce the number of connected components
%TestIm=B;
%imshow(TestIm)

[L Ne] = bwlabeln(TestIm);
glyphs = cell(1 ,Ne)  %%%Initilize glyphs matrix

   for n=1:Ne
    [r c] =find(L==n);
    
    glyph = TestIm(min(r):max(r),min(c):max(c));
   
    glyph = imresize(glyph,[7 5]); 
   
    % Again convert to binaray image
    glyph = double(glyph);
    thresh = graythresh(glyph);
    glyph = im2bw(glyph,thresh); 
    
    glyphs{n} = glyph
    x=input('wait for input: ','s');
    imshow(glyph)
   end
   
N=26;
I= cell(1,N);
count=1;
for i='A':'Z'
    im=imread(strcat('training/',i,'.bmp'));
    im=imresize(im,[7 5]);
    I{count}=im;
    count=count+1;
end


net=newff([0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1; 0 1],[26,26],{'tansig','logsig'},'traingd');
net = init(net);
B=[]; 
count=1;

    for i=1:7
    for j=1:5
    for k=1:26
    B(count,k)=I{k}(i,j);
    end
    count=count+1;
    end
    end
    
C=zeros(26,26);
for i=1:26
        C(i,i)=1;
end
    
net.performFcn = 'sse';
net.trainParam.goal = 1;
net.trainParam.show = 20;
net.trainParam.epochs = 100;
net.trainParam.mc = 0.95;
[net,tr] = train(net,B,C);

A=[];
for i=1:Ne
    count=1;
for j=1:7
    for k=1:5
    A(count,1)=glyphs{i}(j,k);
    count=count+1;
    end
end

e = sim(net,A);
disp(e);
[b c]=max(e);
f=64+c;
d=char(f);
disp(d);
end



