; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFiletreeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "filetree.h"

ClassCount=3
Class1=CFiletreeApp
Class2=CFiletreeDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FILETREE_DIALOG

[CLS:CFiletreeApp]
Type=0
HeaderFile=filetree.h
ImplementationFile=filetree.cpp
Filter=N

[CLS:CFiletreeDlg]
Type=0
HeaderFile=filetreeDlg.h
ImplementationFile=filetreeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFiletreeDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=filetreeDlg.h
ImplementationFile=filetreeDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILETREE_DIALOG]
Type=1
Class=CFiletreeDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE1,SysTreeView32,1350631431
Control4=IDC_EDIT_NAME,edit,1350631552

