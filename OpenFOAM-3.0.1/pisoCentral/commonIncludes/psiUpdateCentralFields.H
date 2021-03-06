{
    psi_own     = fvc::interpolate(psi, own, "reconstruct(psi)");
    psi_nei     = fvc::interpolate(psi, nei, "reconstruct(psi)");
    
    psiU_own    = fvc::interpolate(psi*HbyA, own, "reconstruct(U)");
    psiU_nei    = fvc::interpolate(psi*HbyA, nei, "reconstruct(U)");
    
    phiv_own    = (psiU_own / psi_own) & mesh.Sf();
    phiv_nei    = (psiU_nei / psi_nei) & mesh.Sf();
    
    MRF.makeRelative(phiv_own);
    MRF.makeRelative(phiv_nei);
    
    aphiv_own   = alpha_own*phiv_own - aSf;
    aphiv_nei   = alpha_nei*phiv_nei + aSf;
    
    phid_own    = aphiv_own * psi_own;
    phid_nei    = aphiv_nei * psi_nei;
    
    Dp_own = alpha_own*fvc::interpolate(rho*rAU, own, "reconstruct(Dp)");
    Dp_nei = alpha_nei*fvc::interpolate(rho*rAU, nei, "reconstruct(Dp)");
}

